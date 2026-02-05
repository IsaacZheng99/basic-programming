# LRU算法

## 1. 翻译问题

- LRU的中文翻译是**“最近最少使用”**算法，如果笔者没有记错的话，操作系统教材上也是这么称呼的，但个人认为：根据LRU算法的思想，只记录了数据**最近使用**的情况，并没有体现所谓的**”最少“**；根据LRU单词的英文释义来说，参照牛津词典，recently一词的意思是”not long ago“，而least一词的意思是”smallest in size, amount, degree, etc.“，也就是说least用来修饰recently，表示最近的。所以我个人会翻译成**最近使用算法**。（这里笔者没有去找LRU算法的出处，主要是觉得“最近最少使用”的翻译本身就很有漏洞了）
- 对比FIFO，LRU，LFU：
  - FIFO只关心**第一次加入到缓存的时间**，先创建的先被淘汰，而LRU会将最近使用到的数据**”更新“**，即将该数据放在最新的位置，FIFO则不关注最近是否有使用过。
  - LFU只关心**使用次数**，而LRU只关心**最近是否使用**，或者说是”更新“的时间，这里的更新可以是第一次被加入到缓存，被修改，被访问。（LRU和LFU的对比也佐证了上述对“最近最少使用”这一翻译的反对）
  - LRU-K算法，该算法是结合了LRU和LFU的思想，我觉得它才应该叫”最近最少使用“，这里笔者就不赘述了。

## 2. 核心思路

- 笔者在操作系统中第一次接触LRU算法，它是一种常用的页面置换算法，后续在计算机组成原理中讲到缓存时也提到了该算法。本质是因为缓存的容量是有限的，我们使用LRU算法，将最近未被使用的数据淘汰掉。
- 在具体业务场景中，我们也会用到LRU算法，例如：我们需要存储一个用户最近搜索的20个词条，此时我们就可以用LRU进行数据的更新（这个例子可能不是很好，因为一般这种具体需求是由产品经理或策划来给出的，这里只是举一个例子）。
- 对最近使用的定义：数据第一次被加入到缓存，被修改，被访问都被认为是”使用“了，我们需要标记其最近被使用了。

## 3. 代码实现

### 3.1 python实现

这里先给出一个使用python提供的OrderedDict对象实现LRU的版本：（LeetCode上有一道LRU的题目：[146. LRU 缓存](https://leetcode.cn/problems/lru-cache)）

- 代码如下：

  ```python
  class LRUCache:
  
      def __init__(self, capacity: int):
          self.m_Capacity: int = capacity
          self.m_Cache: OrderedDict = OrderedDict()
  
      def get(self, key: int) -> int:
          iResult: int = self.m_Cache.get(key, -1)
          if iResult != -1:
              self.m_Cache.move_to_end(key)
          return iResult
  
      def put(self, key: int, value: int) -> None:
          self.m_Cache.pop(key, None)
          if len(self.m_Cache) >= self.m_Capacity:
              self.m_Cache.popitem(last=False)
          self.m_Cache[key] = value
  ```

- python3.6之后的dict本身就是有序的，OrderedDict也是有序的，即它们可以直接实现插入新元素时按照插入顺序来保存，我们这里使用OrderedDict也就保存了基本的元素有序，即对self.m_Cache，元素从前到后是”越来越新“的。

- 但由于缓存的大小是有限的，所以对put()方法来说，我们需要额外判断当前数据数量是否达到了上限，如果达到上限，则需要删除最老的元素，即第一个元素，这里使用OrderedDict对象的popitem()接口。

- 对访问操作来说，即get()接口，除了基本的字典get的操作，我们还需要将访问到的元素进行更新，即这里我们通过OrderedDict对象的move_to_end()方法，将访问到的元素放到最后。

### 3.2 通用实现

- 上述python实现，我们通过OrderedDict对象直接实现了LRU的细节，本质上还是在调接口。

- 如果要实现一种通用的做法，也就是需要手动去实现插入有序和更新元素到最新的操作，比较常见的做法是通过一个双向链表实现，但这样会导致查询效率降低为O(n)，如果要解决这个问题，可能最终落地下来就是按照python3.6之后dict的实现了：将key和value分离，key还是用于哈希操作。

- C++实现如下：

    ```c++
    struct Node
    {
        int key, val;
        Node* prev;
        Node* next;
    
        Node()
            : key(-1), val(-1), prev(nullptr), next(nullptr) {}
    
        Node(int key, int val)
            : key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    
    
    class LRUCache {
    public:
        LRUCache(int capacity)
            : capacity(capacity)
        {
            dummyHead = new Node();
            dummyTail = new Node();
            dummyHead->next = dummyTail;
            dummyTail->prev = dummyHead;
        }
    
        ~LRUCache()
        {
            Node* curNode = dummyHead->next;
            while (curNode != dummyTail)
            {
                Node* tempNode = curNode->next;
                delete curNode;
                curNode = tempNode;
            }
    
            delete dummyHead;
            delete dummyTail;
        }
        
        int get(int key)
        {
            if (uMap.find(key) == uMap.end())
                return -1;
            
            Node* curNode = uMap[key];
            removeNodeFromList(curNode);
            addToTail(curNode);
    
            return curNode->val;
        }
        
        void put(int key, int value)
        {
            if (uMap.find(key) == uMap.end())
            {
                if (uMap.size() >= capacity)
                {
                    Node* deleteNode = dummyHead->next;
                    uMap.erase(deleteNode->key);
                    removeNodeFromList(deleteNode);
                    delete deleteNode;
                }
    
                Node* newNode = new Node(key, value);
                uMap.emplace(key, newNode);
                addToTail(newNode);
            }
            else
            {
                Node* curNode = uMap[key];
                curNode->val = value;
                removeNodeFromList(curNode);
                addToTail(curNode);
            }
        }
    private:
        void addToTail(Node* node)
        {
            dummyTail->prev->next = node;
            node->prev = dummyTail->prev;
            node->next = dummyTail;
            dummyTail->prev = node;
        }
    
        void removeNodeFromList(Node* node)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    private:
        int capacity;
        std::unordered_map<int, Node*> uMap;
        Node* dummyHead;
        Node* dummyTail;
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
    ```

