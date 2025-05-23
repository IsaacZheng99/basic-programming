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

