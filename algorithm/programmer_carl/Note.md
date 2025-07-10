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

## 8. Backtrack

**Knowledge Points**: `backtrack and recursion`, `backtrack and tree`, `three core elements of backtrack`, `prune`, `sort and prune`, `combination and partition problems`, `remove repetition: startIndex and nums[i] == nums[i - 1], used std::vector<bool> and nums[i] == nums[i - 1], unordered set`

### 1. Basics

1. `Backtrack` is a way for search.
2. `Backtrack` is a by-product of `recursion`, and if there is `recursion`, there is `backtrack`.
3. `Backtrack` is indeed `brute force` and it's not efficient. We can just `prune` it to make it a little more efficient.
4. `Backtrack` can be abstracted to `tree structure`, because `backtrack` is use to solve problems like we want to recursively find subset in a set, and the size of the set is the width of the tree, while the depth of the recursion is the depth of the tree.
5. Three core elements of `backtrack`:
    1. The `parameters` and `return value` of the `recursive function (backtrack function)`.
    2. The `termination conditions`, which generally is that it comes to the `leaf node`.
    3. The `traversal process of backtrack search`.

### 2. Combination

1. If we simply use `brute force` to solve this problem, we need to write `k` layers of `for loop`, which is impossible when k is large. Instead, we use `backtrack method` to make `recursion` take the place of `for loop`.

2. Don't forget to `prune`.

### 3. Combination (Optimization)

### 4. Sum of Combination Ⅲ

### 5. Alphabet Combination of Telephone Number

### 6. Sum of Combinations

1. For repeatedly using elements, we can just pass `srartIndex = i` to the next layer, rather than `startIndex = i + 1` like before.
2. For `pruning`, `sorting and then pruning` is a common way.

### 6. Sum of Combinations Ⅱ

1. The key of this problem is how to make sure that the `std::vector<>` can have repetitive elements but the `result` can't have repetitive combinations. We can add a `used` `std::vector<bool>` to mark the used elements, or we can just use `startIndex` to judge. Morever, if we use the `tree` structure to illustrate this problem, it will become we just avoid repetition along the current layer of the `tree`, but for the `branch` of the tree, it can have repetitive elements. So there are **two kinds** of `repetition`.

### 7. Partition Palindrome String

1. `Partition problems` are like `combination problems`, and one of the keys is to identify the cut line.

### 8. Restore IP Address

### 9. Subset

1. For this problem, we need to collect **all** the nodes of the `tree`, rather than only the leaf nodes like before.

### 10. Subset Ⅱ

### 11. Non-Descending Subsequence

1. We can't sort the original `std::vector<>` beforehand because this problem needs to find subsequence. Therefore, we can't use the repetition removal logic like `nums[i] == nums[i - 1]`. Instead, we need to create a `set` in each layer of the tree. Note that there should be an individual `set` in each layer and we don't need to `erase` elements because we **don't** need to **backtrack** these `sets`.
2. However, when the original `std::vector<>` can be sorted, the `set` method is much **less** effective than the `used` method and `startIndex` method.

### 12. Full Permutations

1. For `permutation` problems, we need to use `used` `std::vector<bool>` to solve them.

### 13. Full Permutations Ⅱ

1. Fro `permutation` problems, the repetition removal along the `current layer` of the `tree` and the `branch` of the `tree` are both find, but the former one is more effective. (Draw the `tree` structure to compare.)

    ```c++
    if (i && nums[i] == nums[i - 1] && used[i - 1] = false) continue;  // repetition removal along the current layer
    if (i && nums[i] == nums[i - 1] && used[i - 1] = true) continue;  // repetition removal along the branch
    ```

### 14. Reschedule Itinerary

### 15. N-Queen

### 16. Sudoku

## 9. Greedy Algorithm

**Knowledge Points**: `consider one by one`

### 1. Basics

1. `Greedy algorithm` aims to get the **current** optimal solution of each stage and **finally** get the optimal solution. Here are two examples:
    1. There are some coins and we can take `10` of them, then how to get the maximum money? The `greedy algorithm` is to get the coin with the maximum value each time.
    2. For `Knapsack Problems`, we can't simply get the staff with maxmium weight or value each time and we need to use `dynamic programming`.
2. It's **not** easy to determine whether `greedy algorithm` can be used for solving the current problem and we may need to use `mathematical induction` or `reduction to absurdity` to verify. Therefore, if the simulation process of `greedy algorithm` seems to work, we can try it. Otherwise, we may need to use `dynamic programming`.

### 2. Distribute Cookies

### 3. Swinging Sequence

1. If we use `greedy algorithm`, the key is to keep all the `peek values` and delete the other values along each slope. Note that we need to handle the case that there is a flat slope.
2. We can also use `dynamic programming` to solve this problem. And we can use `segment tree` to save time.

### 4. Max Sum of Subsequence

### 5. Best Time to Buy and Sell Stocks Ⅱ

### 6. Jumping Game

### 7. Jumping Game Ⅱ

### 8. Max Sum After K Times of Inversion

1. We can sort the original `std::vector<int>` according to the `absolute value` not just the value, therefore we don't need to compare `num[curIndex]` with `num[curIndex - 1`].
2. In fact, there are two times of `greedy algorithm` being used.

### 9. Gas Station

### 10. Distribute Candies

1. **Two** times of `greedy algorithm`, one is to compare the current value with the left side value and the other is to compare the current value with the right side value. Note that in the second case, the value should be `candies[i - 1] = std::max(candies[i - 1], candies[i] + 1)`, which can guarantee the value satisfies the two cases at the same time. Besides, when comparing the value with the right side value, as the value with smaller index is rely on the value with larger index, we should traverse from right to left.

### 11. Lemonade Change

### 12. Reconstruct Queue Based on Heights

1. When there are more than one dimension, we should consider one by one. If we consider two or more demensions together, it is very likely to make a mistake.

### 13. Ignite the Ballons with the Minimum Number of Arrows

### 14. No Overlapping Intervals

1. When it comes to `delete` elements in arrays like `std::vector<>`, we can use temporary values to represent the interval or we can just change the value of the being removed element to **pretend** it has been removed.

### 15. Divide Letter Intervals

### 16. Combine Intervals

1. Similar to `14. No Overlapping Intervals`, we can change the elements which have been put into the **result** `std::vector<std::vector<int>>` to **pretend** the intervals have been combined.

### 17. Monotonically Ascending Numbers

1. In this problem, we need to traverse from the digit in the **lower** place, because if we traverse from the digit in the higher place, and we find an unsuitable digit, after we modify it, the former digits can be  influenced, but we have traversed them. To sum up, the order in which we traverse depends on whether the modification will **influence** the digits we have traversed. Note that here the `influence` means we have to re-traverse the traversed digits and judge them again and again. For example, in this problem, even if we traverse from the digit in the lower place, when the digit in the higher place is unsuitable, we need to modify the digits lower than it all to `9` and some of them have been modified by `nums[i + 1] -= 1`. But we don't need to judge them again, we just modify them in a uniform way.

### 18. Monitor Binary Tree

## 10. Dynamic Programming

**Knowledge Points**: `dynamic programming vs. greedy algorithm`, `five core elements`, `0-1 backpack`, `rolling array`, `traversal order of 0-1 backpack when using rolling array`, `traversal order of complete backpack when dealing with combination and permutation with rolling array`, `tree based dynamic programming`, `Levenshtein distance`

### 1. Basics

1. For `dynamic programming`, the current **state** is derived from the previous **state**. For `greedy algorithm`, we **directly** get the **local** optimal solution.
2. The five core elements of `dynamic programming`:
    1. The meaning of `dp[]` and `index`.
    2. The `recursive formula`.
    3. The `initialization` of `dp[]`.
    4. The `order` of traversal.
    5. Use an `example` to derive `dp[]`.

### 2. Fibonacci

1. We can simply use **two** variables to take the place of the array.

### 3. Climb Stairs

### 4. Climb Stairs with Minimum Cost

### 5. Different Paths

1. We can use `rolling array` to reduce the dimensionality of `dp array`.

### 6. Different Paths Ⅱ

### 7. Partition Integer

1. For the `recursive formula`, we need to determine how the current integer can be partitioned. There are four cases:

    ```c++
    dp[i] = std::max({dp[i], dp[j] * dp[i - j], j * dp[i - j], dp[j] * (i - j), j * (i - j)});
    ```

    For the second and the third cases, they are equivalent. As for the first case `dp[j] * dp[i - j]`, when `j` is small, `dp[i - j]` will be partitioned into many pieces and this partition has included the case that `j` is larger and `dp[j]` needs to be partitioned.

### 8. Different BST

1. For the `recursive formula`, we need to determine how the current tree can be formed. The key is we need to classify based on which node is the current **root** node.
2. We can conclude based on `7. Partition Integer` and `8. Different BST` that we can get the `recursive formula` based on how to **break the current state**, e.g., number, tree, etc. Actually, the `recursive formula` is indeed to break the current `dp[i]`, but we need to do something like classification to help find the way to break when it comes to the practical cases.

### 9. 0-1 Backpack Basics Ⅰ

1. In `0-1 backpack`, the number is just `1` for each item and we just need to determine whether to choose or not.
2. We can simly use `brute force` to solve `0-1 backpack` problem and for each item, there are two cases: choose or not. Therefore, the time complexity is `O(2^n)` and we can use `backtrack` to solve it.
3. Five core elements:
    1. The meaning of `dp[i][j]`: choose from items `0-i` and the weight of the backpack is `j`.
    2. The `recursive formula`: `dp[i][j] = std::max(dp[i - 1][j - weights[i]] + values[i], dp[i - 1][j])`, which depends on whether we choose the item `i`.
    3. The initialization of `dp[][]`: for `dp[0][i]`, we need to find the minimum `i` which is equal to or greater than `weights[0]`, and for `dp[i][0]`, ther are all `0`.
    4. The order of traversal: it's fine to traverse whether items or weights first, but maybe it's easier to understand to firstly traverse items.
    5. The examples.

### 10.  0-1 Backpack Basics Ⅱ

1. `Rolling array`: after the upper layer has been used, we don't need to use it anymore, then we can just overlap it with the value of the current layer, in this case we can use `rolling array`.

    For example, for

    `dp[i][j] = std::max(dp[i - 1][j - weights[i]] + values[i], dp[i - 1][j])`,

    we can simply use

    `dp[i][j] = std::max(dp[i][j - weights[i]] + values[i], dp[i][j])`,

    therefore the first dimension can be deleted, and the formula becomes

    `dp[j] = std::max(dp[j - weights[i]] + values[i], dp[j])`.

    Note that when deleting the dimension, we need to leave the right dimension, which means we need to determine the meaning of `dp[]`, which is one of the `five core elements of dp`.

2. The order of traversal in the `dp[]` case is much different than the case with `dp[][]`:

    1. We need to traverse the weights **from bigger to smaller**, because if we traverse from smaller weights, the `i-th` item can be used more than once and the basic reason is that the current state `dp[i][j]` has overlapped the former state `dp[i - 1][j]` because of `rolling array` and when it comes to `dp[i][j + 1]`, it will use `dp[i][j]` instead of `dp[i - 1][j]`.
    2. We must traverse the items first, becuase if we traverse the weights first, it comes to the situation that we simply put a **single** item into each backpack. The basic reason is we can't leverage the smaller backpack, which is `dp[j - weights[i]]` because we are traversing the weights from bigger to smaller.

### 11. Segment Subsets with Equal Summation

1. For `brute force`, we can use `backtrack`.
2. In this case, the weight of the item is just the value of the item. 
3. `0-1 backpack` problems don't only solve the problems of the greatest value, but also the problems that whether a backpack can be filled to capacity, in which case we just need to check whether `dp[weight] == weight`.

### 12. Wight of the Last Stone Ⅱ

1. First of all, we need to translate the problem into `0-1 backpack` problem. Essentially, the problem is to find two groups of stones, which have the same weight as much as possible. The reason is however we make two stones crash each other, it will become one whole group of stones crash the other group in the end. To help us understand, we can take the process of crash as the situation that two stones **are decreasing the same weight** at the same time, which is the smaller weight of the two stones.

### 13. Target Sum

1. To translate this problem into `0-1 backpack`, we have these formulas: `left - right = target`, `left + right = sum`, then `left = (sum + target) / 2`.

    Moreover, for the initialization of `dp[]`, we have `dp[0] = 1` because we can make all the numbers be right, then `left = 0` and this is one case which is always there.

    However, when we use `2-D dp[][]`, the initialization will be much different, in this case we need to traverse the items from `1`, therefore we need to check whether `nums[0] == 0` and if it's true, we have to make `dp[0][0] = 2`, otherwise we can make `dp[0][0] = 1`. But for `1-D dp[]`, we can simply traverse the items from `0` and make `dp[0] = 1`, if we also want to traverse items from `1` in this case, we have to do the same initialization as the `2-D` case.

2. For `brute force`, we can use `backtrack`.

### 14. One and Zero

1. In this problem, the dimension of the `backpack` is no more just `1` but becomes `2`.

### 15. Complete Backpack Basics

1. If we use `2-D dp[][]`, the `recursive formula` is different from the `0-1 backpack` case. In the `complete backpack` case, we also consider whether put the current item to the backpack, when we don't put the `i-th` item, we have `dp[i - 1][j]`, however, when we put the `i-th` item, we have `dp[i][j - weights[i]] + values[i]` instead of `dp[i - 1][j - weights[i]] + values[i]` because the `i-th` item can be put any times. Here we are discussing put or not put, it means when the weight of the current backpack is enough for the `i-th` item, we can put or not put it in this time.
2. If we use `1-D dp[]`, we can simply decreasing the first dimension of `dp[][]`, which is used in the `2-D` case, meaning the `order of traversal` is as **same** as that of the `2-D` case. The reason is that there is no such **overlapping problem**, as we indeed need to use `dp[i][j]` instead of `dp[i - 1][j]`. Morever, without the overlapping problem, we don't need to traverse the items from bigger to smaller, then we can either traverse items first or the weights of the backpack first.
3. To sum up, when it comes to `complete backpack`, the `recursive formula` is different, and because we are using `dp[i][j]` instead of `dp[i - 1][j]`, there is no overlapping problem and the `order of traversal` has no constraints in this case.

### 16. Change Exchange Ⅱ

1. For the `order of the traversal`, when we use `2-D dp[][]`, it's fine to traverse items first or weights first. However, if we use `1-D dp[]`, we **have to** traverse the items first because we are calculating number of **combinations**. If we traverse the weights first, we will calculate the number of **permutations**. The basic reason is the overlapping problem. Specially, when we use `2-D dp[][]`, the items are from `0` to `nums.size() -1` in whatever order we use, but when we use `1-D dp[]`, we don't have the index of the items anymore and if we traver the weights first, the overlapping problem will make the result sum up and get a wrong result.

### 17. Sum of Combination Ⅳ

### 18. Climb Stairs (Advanced Edition)

### 19. Change Exchange

1. For the `initialization of dp[]`, we need to make `dp[0] = 0` and moreover, `dp[i] = INT_MAX` because we need to get minimum value by `dp[j] = std::min(dp[j], dp[j - coins[i]] + 1)`.

### 20. Perfect Square

### 21. Word Splitting

1. Note that this problem is essentially a `permutation` problem.

### 22. Multiple Backpack Basics

1. We can simply convert `multiple backpack` problems to `0-1 backpack` problems by unfolding items from one group to **individual** items.

### 23. Raid Homes and Plunder Houses

### 24. Raid Homes and Plunder Houses Ⅱ

1. For a `ring array`, there are three cases: (I personally think there are just two cases, i.e., the last two cases.)

    1. Not consider the first element and the last element.
    2. Conisder the first element, but not consider the last element.
    3. Consider the last element, but not consider the first element.

    For the last two cases, they are both contain the first case. So we can just use two `dp[]` to slove this problem.

2. Originally, I define the `dp[]` arrays based on whether consider the first element. This definition is essentially as same as the reference definition.

### 25. Raid Homes and Plunder Houses Ⅲ

1. For `brute force`, we can use `postorder traversal` and we can use `memorized recursion` to prune.
2. This problem is `tree based dynamic programming`, we need to combine `the three core elements of recursion` with `the five core elements of dynamic programming`.

### 26. Best Time to Buy and Sell Stocks

### 27. Best Time to Buy and Sell Stocks Ⅱ

### 28. Best Time to Buy and Sell Stocks Ⅲ

### 29. Best Time to Buy and Sell Stocks Ⅳ

### 30. Best Time to Buy and Sell Stocks with Freeze Period

1. For the `meaning of dp[]` in this problem, we need to classify carefully. I personally list three cases (the reference code lists four cases, but in the summary chapter, the reference solution also lists three cases and they are the same as mine):
    1. `0`: The stock is already bought, maybe it's bought today or on a previous day.
    2. `1`: The stock is sold today.
    3. `2`: The stock was sold on an earlier day, but not today and the stock has not been bought.

### 31. Best Time to Buy and Sell Stocks with Commission

### 32. Longest Increasing Subsequence

1. Compared with `33. Longest Continuous Increasing Subsequence`, the subsequence is not continuous in this problem, which means the current state `dp[i]` is influenced by all the previous states `dp[0], dp[1], ..., dp[i - 2], dp[i - 1]`.

### 33. Longest Continuous Increasing Subsequence

### 34. Longest Common Subarray

### 35. Longest Common Subsequence

1. For the `meaning of dp[]`, we need to define `dp[i][j]` as the longest common subsequence of `text1[0: i - 1]` and `text2[0: j - 1]`, which doesn't necessarily need to end with `text1[i - 1]` and `text2[j - 1]`. But for `34. Longest Common Subarray`, `dp[i][j]` has to end with `nums1[i - 1]` and `nums2[j - 1]` because the subarray has to be continuous, otherwise the `recursive formula` can't satisfy the continuty.

### 36. Non Intersecting lines

### 37. Maximum Sum of Subarray

### 38. Check Subsequence

1. For the `recursive formula`, it can be same as that of `35. Longest Common Subsequence`. However, for this problem, as we have to match the **whole** `string s` with the subsequence of `string t`, we can simply make `dp[i][j] = dp[i][j - 1] if s[i - 1][j] != t[j - 1]`, which means we can only ignore the characters of `string t`. Therefore, the `meaning of dp[i][j]` can be  when we match the **whole** `s[0: i - 1]` with the subsequence of `t[0: j - 1]`, the maximum length of the subsequence is `dp[i][j]`. Moreover, this problem is an introduction to the `Levenshtein Distance (edit distane)`.

### 39. Number of Subsequences

### 40. Delete Operation of Two Strings

### 41. Levenshtein Distance (Edit Distane)

1. For the `recursive formula`, we need to classify carefully when `word1[i - 1] != word2[j - 1]`. Essentially there are just three cases:

    1. Delete `word1[i - 1]`: `dp[i][j] = dp[i - 1][j] + 1`.
    2. Delete `word2[j - 1]`: `dp[i][j] = dp[i - 1][j] + 1`.
    3. Replace `word1[i - 1]` with `word2[j - 1]`: `dp[i][j] = dp[i - 1][j - 1] + 1`.

    Note that the add operation is essentially same as the delete operation.

### 42. Palindrome Substring

1. For the `order of traversal of dp[][]`, as we have `dp[i][j] = dp[i + 1][j - 1]`, we need to traverse `i` from bigger to smaller.
2. For the `palindrome string` problems, we can try to use `double pointers` to solve them and for this problem, use `double pointers` will save memory than using `dynamic programming`.

### 43. Longest Palindrome Subsequence

