#pragma once

#include <queue>


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};


class Solution116
{
public:
    Node* connect(Node* root)
    {
        std::queue<Node*> queue;
        if (root)
            queue.push(root);

        while (!queue.empty())
        {
            int curLevelSize = queue.size();
            for (int i = 0; i < curLevelSize; i++)
            {
                Node* cur = queue.front();
                queue.pop();
                if (i != curLevelSize - 1)
                    cur->next = queue.front();
                else
                    cur->next = nullptr;
                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }
        }

        return root;
    }
};