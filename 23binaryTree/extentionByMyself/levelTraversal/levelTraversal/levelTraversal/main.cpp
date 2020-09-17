//
//  main.cpp
//  levelTraversal
//
//  Created by mingyue on 2020/9/17.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void binaryTreeLevelOrder(TreeNode * root)
{
    if (!root) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        cout << p->val << " ";
        if (p->left) {
            q.push(p->left);
        }
        if (p->right) {
            q.push(p->right);
        }
    }
}

int main(int argc, const char * argv[]) {
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 6;
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 2;
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2->val = 8;
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3->val = 0;
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4->val = 4;
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5->val = 7;
    struct TreeNode *node6 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6->val = 9;
    struct TreeNode *node7 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7->val = 3;
    struct TreeNode *node8 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node8->val = 5;
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;
    node3->left = nullptr;
    node3->right = nullptr;
    node4->left = node7;
    node4->right = node8;
    node5->left = nullptr;
    node5->right = nullptr;
    node6->left = nullptr;
    node6->right = nullptr;
    node7->left = nullptr;
    node7->right = nullptr;
    node8->left = nullptr;
    node8->right = nullptr;
    
    binaryTreeLevelOrder(root);
    cout << endl;
    
    return 0;
}
