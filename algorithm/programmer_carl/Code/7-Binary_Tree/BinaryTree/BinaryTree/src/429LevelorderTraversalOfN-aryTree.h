#pragma once

#include <vector>
#include <queue>


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution429
{
public:
    std::vector<std::vector<int>> levelOrder(Node* root)
    {
        std::vector<std::vector<int>> result;
        std::queue<Node*> queue;
        if (root)
            queue.push(root);

        while (!queue.empty())
        {
            std::vector<int> curLevelResult;
            int curLevelSize = queue.size();
            for (int i = 0; i < curLevelSize; i++)
            {
                Node* cur = queue.front();
                queue.pop();
                curLevelResult.push_back(cur->val);
                for (Node* node : cur->children)
                    queue.push(node);
            }

            result.push_back(curLevelResult);
        }

        return result;
    }
};