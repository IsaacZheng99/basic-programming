# Note for Learning Programmer Carl Algorithm

## 1. Array

**Knoweldge Points**: `principle of cyclic invariants`, `double pointers`, `fast and slow pointers`, `std::vector<>::reserve() and std::vector<>::resize()`,  `sliding window`, `prefix sum`

### 1. Basics

1. `Array` is stored continuously in memory.

### 2. Binary Search

1. For `mid`, the standard approach is to **round down**: `int mid = left + (right - left) / 2` because if we use round down, it may lead to endless loop (I don't really know the mathematical reason).

2. For `boundary checking`, we need to focus on the **Principle of cyclic invariants**, which is the **invariant definition of interval** in this case.

    Specifically, there are **three** aspects: the initial values of `left` and `right`, the `condition of the while loop`, and the `update of left and right`.

    We can fix `left` and classify based on `right`, i.e., `[left, right]` and `[left, right)`.

    For example, if we choose `[left, right]`, we have: 

    ```c++
    int main()
    {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right)
        {
            //...
            {
                left = mid + 1;
            }
            {
                right = mid - 1;
            }
        }
    }
    ```

    If we don't make these three aspects consistent, we may also walk towards to endless loop.

### 3. Remove Elements in Place

1. The `slow pointer` mark the place which need to be replaced and the `fast pointer` find the next number which can be put to the place marked by the `slow pointer` and after replacement, they move together.

### 4. Sorted Squares

1. The difference between `std::vector<>::reserve()`  and `std::vector<>::resize()`.
2. Think carefully where the `pointers` start from.

### 5. Minimum Length of Sub-array

1. `sliding window` can also be represented by `double pointers`.
2. The key points of `sliding window` is what the **content** inside of the window is and how to **move the starting and ending positions**.

### 6. Generate Spiral Matrix

1. `Principle of cyclic invariants`:

    1. the upper row from left to right

    2. the right column from top to bottom

    3. the bottm row from right to left

    4. the left column from bottom to top

    5. if we choose `left closed right open interval`: 

        ```c++
        for (int col = loop; col < n - loop - 1; col++)
        ```

        if we choose `left closed right closed interval`: 

        ```c++
        for (int col = loop; col <= n - loop - 1 - 1; col++)
        ```

### 7. Interval Sum

1. `Prefix sum` can help us handle interval problems.

### 8. Buy Land

1. This is essentially an interval problem and we can use `Prefix sum` to solve it.

## 2. Linked List

**Knowledge Points**: `dummy node`, `double pointers`, `fast and slow pointers`

### 1. Basics

1. Variants: `Single Linked List`, `Doubly Linked List`, `Cyclic Linked List`
2. Operations: `delete node`, `add node`.
3. `Complexity comparison` between `array` and `linked list`.

### 2. Remove Elements

1. `Dummy node` can help use handle nodes in a uniform way.
2. Remember to `delete` the `dummy node` or other nodes we add for simplicity if needed.

### 3. Custom Linked List

1. `Dummy node` can help **insert** node **before** a node whose index is given.
2. Using a variable `m_Length` to record the current **length** of the linked list can simply the code.

### 4. Reverse List

1. `Double pointers`: `pre` and `cur` in this case, besides `next` is used to temporarily record `cur->next`.
2. Notice the **order** of updating the two pointers.
3. `Recursion` can also be used to solve this problem.

### 5. Swap Pairs

1. `Dummy node` can help us handle nodes in a uniform way, e.g., special judgement of the `head node` or some special cases like whether there is one or two nodes left in this problem.

### 6. Remove the N-th node from end

1. `Dummy node` can help us **remove** nodes.
2. `Fast and slow pointers`: the fast pointer firstly move `n` steps and then the two pointers move together until the fast pointer arrives at the end, and now the slow pointer is pointing to the `n-th` node from end. Please notice that this is just a rough description and in the real code we may need to use `dummy node`, decide how many steps the fast pointer should actually move, and hot to end the co-move.

### 7. Get Intersection Node

1. `Fast and slow pointers`: the fast pointer firstly move forward to make the left length of the current linked list be equal to the length of the other linked list, which is shorter.

### 8. Detect Cycle

1. `Fast and slow pointers`: the fast pointers moves `2` steps at each time, while the slow pointer moves `1` step at each time and finally they will meet in the cycle if there is a cycle. (Note that there comes to some math.)

## 3. Hash Table

**Knowledge Points**: `array, set, map` are all `hash tables`, `prune`, `addition overflow`

### 1. Basics

1. `Hash table`: a data structure that is directly accessed based on the value of a key.
2. `Hash function`: map the `key` to the `index`.
3. `Hash collison`: we can use `zipper method`, `linear detection method`, `double hashed method`, etc. to solve this problem.
4. Common form: `array`, `set`, and `map`.
5. `Hash table` can help us quickly find whether an element has appeared or not at the cost of additional space expenses.

### 2. Is Anagram

1. There are only lowercase letters in this problem, meaning we know the exact maximum size in advance, so we can just use `array` not `map` to solve it.
2. Learn to handle data in just **one** `hash table` if possible.

### 3. Intersection

1. As we don't know the possible maximum size in advance, we need to use `set`. (Note that `set` needs more space and time (hash function needs time) than `array` does.)
2. `std::unordered_set` can be constructed based on a given `std::vector`, vice versa.

### 4. Happy Number

### 5. Sum of Two Numbers

### 6. Add Four Numbers

### 7. Ransom Letter

### 8. Sum of Three Numbers

1. No need to use `hash table`, use `double pointers`.
2. We can `prune` to make it faster.
3. We need to remove duplicates and the key is where to write the removing code.

### 9. Sum of Four Numbers

1. There are two classes of `pruning` in this problem.
2. Notice the problem of `addition overflow`.
3. We need to remove duplicates and the key is where to write the removing code.

## 4. String

**Knowledge Points**: `double pointers`, `KMP: next array (essentially a partial match table, prefix table), maximum length of same prefix and suffix`

### 1. Reverse String Ⅰ

1. `Double pointers`.
2. Learn to modify `the three expressions in for loop` to simplify the code.

### 2. Reverse String Ⅱ

### 3. Replace Number

1. Get `std::string` from input: 

    ```c++
    std::string s;
    std::cin >> s;

2. Use `std::string::resize()` to change the size.
3. After we resized the array, we sometimes need to change the value **from back to front**. In fact, when we encounter problems like filling a string, we can usually expand it first and then operate from back to front.

### 4. Reverse Words

1. Delete space:
    1. We can use `std::string::erase()` to delete any element in a `std::string` but it has a complexity of `O(n)`. In this case, we can use `double pointers` to delete space.
    2. We can handle `spaces` in a uniform way, i.e., we ignore all the original spaces and when it comes to the **middle** space, we **manually add** one space.
2. Reverse: reverse globally, then reverse locally.

### 5. Rightly Rotate String

1. Reverse globally, then reverse locally. We can also reverse locally and then globally in this problem.

### 6. strstr()

1. `KMP`: when we can leverage the mismatched but traversed data, it comes to `KMP`.
    1. `Next array`: it is essentially a `partial match table (prefix table)`. It records the maximum length of same prefix (without the last character) and suffix (without the first character) of the string before index `i` (including `i`). Thus, it can help us go back to the matched position, not just the next position.
    2. `Maximum length of same prefix and suffix`:
        1. For `"a"`, it's `0`.
        2. For `"aa"`, it's `1`.
        3. For `"aaa"`, it's `2`.
        4. For `"aaab"`, it's `0`.
    3. `Get next array`:
        1. The index `j` is not only the index of the end of the prefix, but also the length of the longest common prefix and suffix.
        2. `Go back`: `j = next[j - 1]` can help us go back becasue we have matched prefix1 and suffix1 until `j` and `next[j - 1]` tells we have also matched another pair of predix2 and suffix2 in the predix1. By conveying the same substrings, we can use `next[j - 1]` to find the matched pair.
    4. Summary: the `next array` is the key and in the `get next array` and `match` processes, there are two commonalities: one is when the two characters are different, we need to **go back**, the other one is when the two characters are same, the `i` and `j` pointers will move forward together.

### 7. Repeated Substring

1. `Directly match`: 

    ```c++
    bool repeatedSubstringPattern(std::string s)
    {
        std::string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != std::string::npos)
            return true;
        return false;
    }
    ```

    We can simply the code:

    ```c++
    bool repeatedSubstringPattern(std::string s)
    {
    	return (s + s).find(s, 1) != s.size();
    }
    ```

2. Match based on `KMP`: the problem is essentially to judge if there is a pattern string in the given string and it can construct the given string by repeat (or based on `3.7.1`, it becomes if `s` in `s + s` and the begin position is not `s.size()`). Moreover, in `programmer carl`, there is another solution based on `KMP` which needs some math to prove the sufficiency and necessity.

## 5. Double Pointers

**Knowledge Points**: `fast and slow pointers`, `pre and cur pointers`

### 1. Remove Elements In Place

1. `Fast and slow pointers`: the key is to define the `fast and slow pointers` and in this problem the `fast pointer` is pointing to **a qualified element** that is not equal to the target value and the `slow pointer` is pointing to the **place** where the qualified elements can be put.

### 2. Reverse String Ⅰ

### 3. Replace Number

### 4. Reverse Words

### 5. Reverse List

### 6. Remove the N-th node from end

### 7. Get Intersection Node

### 8. Detect Cycle

### 9. Sum of Three Numbers

### 10. Sum of Four Numbers

## 6. Stack and Queue

**Knowledge Points**: `std::stack`, `std::queue`, `std::string::push_back()`, `std::string::pop_back()`, `std::stoi()`, `std::to_string()`, `stoll`, `monotomous queue`, `priority queue`, `std::priority_queue`, `max heap`, `min heap`, 

### 1. Basics

1. In `C++`, the `std::stack` and `std::queue` **don't** provide `iterator` to iterate the elements.

2. We can tack `std::vector`, `std::list` or `std::deque` as the underlying container. In `SGI STL`, the default container of `std::stack` and `std::queue` is `std::deque`. We can call `std::stack` and `std::queue` as `container adapter`.

    ```c++
    std::stack<int, std::vector<int>> stack;
    std::queue<int, std::deque<int>> queue;
    ```

### 2. Implement Queue Based on Stack

1. Use two `stacks`, one is for `data in` and the other is for `data out`.
2. We can directly get the size of the `stack` by `std::stack<>::size()`.

### 3. Implement Stack Based On Queue

1. If we still use two `queues`, they are essentially the same because if the `queue` accept the output of the other `queue`, this `queue` will just become a copy of the output `queue`. Therefore, we only need one `queue` in this problem by push the output elements to the `queue` again.
2. We can directly get the size of the `queue` by `std::queue<>::size()`.

### 4. Valid Brackets

1. We can use `stack` to handle with brackets and paths. (In the case below, we finally enter the `a` directory.)

    ```c++
    cd a/b/c/../../
    ```

### 5. Remove Duplicates

1. The `std::string` provides two methods: `push_back()` and `pop_back()` and we can directly take `std::string` as a `stack` to save space.

### 6. Evaluate RPN

1. `RPN` is equivalent to the `backorder traversal` of `binary tree`.
2. We can use `std::stoi()` to transform `std::string` to `int`, `std::to_string()` to transform `int` to `std::string`, and `stoll()` to transform `std::string` to `long long`.

### 7. Max Value in Sliding Window

1. We need to use `monotomous queue` to record all the "possible maximums" because if we poped the current maximum value, we need to know the second greatest value.
2. `Monotonous queue` can be implemented based on `std::deque` because we need to `pop_back()` elements and get the maximum value by `front()`.

### 8. Top-k Frequent Elements

1. We can use `priority queue` to solve the `top-k` problems.
2. In `STL`, `std::priority_queue` is implemented based on `max heap` by default, which is a `complete binary tree` implmented by `std::vector`. If we want to implement `std::priority_queue` based on `min heap`, we need a comparison which returns `left > right`.
3. In this problem we need to use `min heap`. If we use `max heap` in this problem, we need to sort all the frequencies and then pop `k`  elements, but if we use `min heap`, we can just sort part of them and pop until there are `k` frequencies left, which are not sorted.

## 7. Binary Tree

**Knowledge Points**: `variants: full binary tree, complete binary tree, binary search tree (binary sort tree), balanced binary search tree (AVL tree)`, `store binary tree: linked and sequential`, `traverse: preorder, inorder, postorder traversal (DFS), levelorder traversal (BFS)`,  `three core elements of recursion`, `complexity`, `height`, `depth`, `the relationship between the current problem and the traversal of binary tree`, `when does the recursive function need a return value`, `BST and inorder traversal`

### 1. Basics

1. Common variants:
    1. `Full binary tree`: the depth is `k` and the count of the nodes is `2^k - 1`.
    2. `Complete binary tree`: except the last layer, all the other layers have the maximum amount of nodes,and the nodes in the last layer must be on the leftmost side. The `priority queue` can be implemented by `heap`, which is usually a `complete binary tree`.
    3. `Binary search tree (binary sort tree)`: it is a sorted tree and satisfies the values of the nodes in the left sub-tree are all less than the value of the root node if there is a left sub-tree, and the values of the nodes in the right sub-tree are all greater than the value of the root node if there is a right sub-tree, moreover, the left and right sub-trees also satisfy the two rules.
    4. `Balanced binary search tree (AVL tree)`: it's a `null tree` or the height difference of the left sub-tree and right sub-tree is less than or equal to `1`.
        1. We won't generally talk about individual `balanced binary tree` because the **balanced** property is used to decrease complexity in specialized scene, e.g., `binary search tree`. A simple `balanced binary tree` is not very specialized.
        2. The `std::map`, `std::set`, `std::multimap`, `std::multiset` in `C++` is implemented based on `balanced binary search tree`.
2. How to store binary tree?
    1. `Linked storage`: use `pointer`.
    2. `Sequential storage`: use `array`, e.g., if the index of the parent node is `i`, the index of the left child node is `2 * i + 1` and the index of the right child node is `2 * i + 2`.
3. How to traverse binary tree?
    1. `DFS`: `preorder, inorder, postorder traversal`. We can use `stack` to implement.
    2. `BFS`: `levelorder traversal`. We can use `queue` to implement.

### 2. Recursive Traversal of Binary Tree

1. Three core elements of `recursion`:
    1. The `parameters` and `return value` of the `revursive function`.
    2. The `termination conditions`.
    3. The `logic in one recursive layer`.

### 3. Iterative Traversal of Binary Tree

1. We can use `stack` to implement traversal.
2. For `preorder traversal`, the orders of accessing the nodes and pushing the values of the nodes into the result vector are the same. But for `inorder traversal`, they are different. Therefore, we can't simply change the code of `iterative preorder traversal` to get the code of `iterative inorder traversal`. So in this case we use `pointer` to help access the current node and the `stack` is still used to temporarily store the nodes.
3. For `preorder traversal`, we can get the `mid-left-right` result. As for `postorder traversal`, we need to get the `left-right-mid` result. Therefore, we can simply change the result of `preorder traversal` to `mid-right-left` and **reverse** it to get `left-right-mid`.
4. If we compare the **complexity** of `revursive traversal` and `iterative traversal`, the time complexity is both `O(n)` and the space complexity if both `O(h)`, but for `recursive traversal`, it uses the `Call Stack`, which needs to store more information and it may lead to `stack overflow` as the size of it is limited, while for `iterative traversal`, the `stack` is created by the programmer, which will use the `heap memory` (the elements stored by `std::stack` is on the `heap`) and won't cause `stack overflow`. Therefore, we need to avoid use `revursive method` in real projects.

### 4. Uniform Iterative Traversal of Binary Tree

1. Two ways: `null pointer mark` and `bollean mark`. We simply use another variable to mark the state, which implies that we **have accessed** the current node but we **havn't handled** it and we will push it to the stack **again** but **mark** it, then next time we access it again, we will handle it, meaning we will put the value of it to the result vector.

### 5. Levelorder Traversal of Binary Tree

#### 1. Leetcode 102 Levelorder Traversal of Binary Tree

1. We can use `queue` to implement iterative levelorder traversal and notice that don't directly use `queue.size()` because it will change in the `for loop`.
2. For recursive levelorder traversal, we need to add a variable `depth` to record the current depth of the current accessed node. Notice that the return type of `std::vector<>::size()` is `size_t`, which is `unsigned`, so if we want to compare it to, e.g., the depth in this case, we can't use `result.size() - 1 < depth` because `result.size() - 1` will give us a very **big positive integer**, we should use `result.size() < depth + 1` instead.
3. Do not use `stack` to implement levelorder traversal because we may begin to traverse the next level without finishing the traversal of the current level.

#### 2. Leetcode  107 Levelorder Traversal of Binary Tree Ⅱ

#### 3. Leetcode 199 Right View of Binary Tree

#### 4. Leetcode 637 Average Value of Each Level

#### 5. Levelorder Traversal of N-ary tree

#### 6. Max Value of Each Level

#### 7. Fill Next Pointer with the Right Node

#### 8. Fill Next Pointer with the Right Node Ⅱ

#### 9. Max Depth of Binary Tree

#### 10. Min Depth of Binary Tree

### 6. Invert Binary Tree

1. Essentially, we just need to invert two children nodes of each node. Therefore, we can choose whatever `traveral methods`. But for `recursive inorder traversal` and `iterative inorder traversal`, the original code will cause the left sub-trees to be inverted twice and the right sub-trees to remain the same, and we can change the `invert(root->right)` to `invert(root->left)` to avoid this or we can use the uniform iterative traversal, becuase we use `stack` to store the nodes in this case.

### 7. Is Symmetric Binary Tree

1. Notice that we need to compare the two nodes in the synnmetric places.

### 8. Max Depth of Binary Tree

### 9. Min Depth of Binary Tree

1. Notice that the condition that the current node has no left child node and no right child node at the same time is the key.

### 10. Number of Nodes in Complete Binary Tree

1. When we recursively go deep from the left and right to the bottom seperately and get the `leftDepth` and `rightDepth`, if they are the same, the current tree is a `full binary tree`. If not, we can split it to left sub-tree and right sub-tree and recursively do the same action to these two sub-trees. Finally we can get all the **small** `full binary trees` and now we can go back recursively to sum the counts and get the final count.

### 11. Is Balanced Binary Tree

1. Sometimes we can assign a special value to the return value of the `recursive method` to represent another type of data.
2. Notice the difference of `depth` and `height` and the corresponding methods to get them.

### 12. All Pahts to the Leaf Nodes

1. We should try to find the relationship between the current case and the **traversal** of binary tree, meaning when we solve the current problem, we should notice that if there comes to the **traversal** of binary tree? If it does, we should notice **which** traversal method we should use. For example, in this case, we need to record all the paths from the root node to the leaf nodes, so we will use the `preorder traversal`. Then it will help us construct the whole framework for solving the current problem.

2. When it comes to the leaf nodes, we should notice that the termination condition for the recursion may not be `cur == nullptr` but `cur->left == nullptr and cur->right == nullptr`, and we also need to handle the case that `cur == nullptr`.

3. One recursion corresponds to one backtrack.

4. ```c++
    std::vector<>::pop_back();
    std::string::pop_back();
    ```

### 13. Sum of Values of Left Leaf Nodes

1. The key is to find out the definition of  `left leaf nodes`: if the left child node is not `nullptr` and the two children nodes of this left child node are both `nullptr`, then this left child node is a `left leaf node`. In fact, this judgement adds an extra layer compared to the normal problems, because we need to judge if a node is a `left leaf nodes` throught its parent node **not itself**.

### 14. The Value of the Lowest and Leftmost Node

1. This problem involves the `depth` of the node, so if we want to use `recursive method` to solve it, we need to handle the `depth` part and in this case we use a parameter `depth` to record the depth of the current node and use `member variable` `m_MaxDepth` to record the depth of the  `lowest` node.

### 15. Check the Sum of Paths to Leaf Nodes

1. When does the `recursive function` need a `return value`: (Note that the discussion is based on whether we need to search the whole tree.)
    1. If we just need to get one workable result, we need the `return value` to tell us we have found a suitable result and we can return now.
    2. If we need to search the whole tree, whether we need a `return value` depends on whether we need to handle the `return value`.

### 16. Construct a Binary Tree Based on Inorder and Postorder Traversal Sequences

1. When it comes to split an array, we need to keep the spliting way the same, e.g., we always make the new interval be left closed and right open.
2. If possible, don't create new `std::vector<>` during the traversal, we can just add two parameters to indicate the beginning and end of the new interval.

### 17. Max Binary Tree

1. Notice that we should split the array in a uniform way.

### 18. Combine Two Binary Trees

1. When it comes to use `iterative method` to compare two trees, we should notice the order in which the nodes enter the `queue` and  which nodes can be allowed to enter the `queue`.

### 19. Search a Node in a Binary Search Tree

1. For `BST`, if we want to use `iterative method` to search the node, we don't need the `stack` or `queue` to help us store nodes because we can directly find the next node to handle. As for normal binary trees, we need to **backtrack** from left to right or from right to left, so we need containers to temporarily store the nodes.

### 20. Verify Binary Search Tree

1. When it comes to `BST`, we can use `inorder traversal` to simplify the code.
2. For this problem, we may set a global variable `CurMax` to record the current max value, but if there is a use case which has been set as `INT_MIN`, there will have problems. So we can just record the pre-accessed node, and every time we compare `cur->val` with `pre-val` and update `pre pointer`. This process can also be promoted to the case that we want to get the max value or min value of a ordered sequence, we can't simply set an initial **extremum**, but we should **compare** the previous value with the current value.

### 21. Min Absolute Difference in BST

### 22. Mode in BST

### 23. Lowest Common Ancestor (LCA)

1. `Postorder traversal` is naturally **retrospective** process and in this problem, we need to **backtrack**.

### 24. LCA in BST

1. The key for this problem is that when we traverse the `BST` from top to bottom, the first node whose value is between the value of `p` and the value of `q` is the `LCA`. Besides, as we don't have to handle the middle node, we don't care about the traversal order.

### 25. Insert a Node to BST

### 26. Delete a Node in BST

### 27. Trim BST

1. For `recursive method`, the key is to take advantage of the `return value` of the `recursive function`. For `iterative method`, we can firstly make the `root` node be in the correct interval, then make the left sub-tree and right sub-tree be in the correct interval separately.

### 28. Turn Sorted Array to Balanced BST

1. When to calculate `mid`, it's better to use `int mid = left + (right - left) / 2`.
2. When it comes to `std::vector<>`, it's better to use `index` to operate the original `std::vector<>` instead of creating new `std::vector<>`.

### 29. Turn BST to Greater Sum Tree









