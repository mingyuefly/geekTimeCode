//
//  main.cpp
//  loopTraversal
//
//  Created by mingyue on 2020/9/17.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - inOrder
void inOrderWithoutRecursion(TreeNode *root)
{
    if (!root) {
        return;
    }
    TreeNode *p = root;
    stack<TreeNode *> s;
    while (!s.empty() || p) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
    cout << endl;
}

void inOrderWithoutRecursion2(TreeNode* root)
{
    //空树
    if (root == NULL)
        return;
    //树非空
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
    cout << endl;
}

void inOrder(TreeNode *root)
{
    if (!root) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

#pragma mark - preOrder
void preOrderWithoutRecursion(TreeNode *root)
{
    if (!root) {
        return;
    }
    TreeNode *p = root;
    stack<TreeNode *> s;
    while (!s.empty() || p) {
        while (p) {
            cout << p->val << " ";
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    cout << endl;
}

void preOrderWithoutRecursion2(TreeNode* root)
{
    if (root == NULL)
        return;
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (!s.empty() || p) {
        if (p) {
            cout << p->val << " ";
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    cout << endl;
}

void preOrderWithoutRecursion3(TreeNode* root)
{
    if (root == NULL)
        return;
    stack<TreeNode*> s;
    TreeNode* p = root;
    s.push(root);
    while (!s.empty())  //循环结束条件与前两种不一样
    {
        //这句表明p在循环中总是非空的
        cout << p->val << " ";
        /*
        栈的特点：先进后出
        先被访问的根节点的右子树后被访问
        */
        if (p->right)
            s.push(p->right);
        if (p->left)
            p = p->left;
        else {
            //左子树访问完了，访问右子树
            p = s.top();
            s.pop();
        }
    }
    cout << endl;
}

void preOrder(TreeNode *root)
{
    if (!root) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

#pragma mark - postOrder
void postOrderWithoutRecursion(TreeNode* root)
{
    if (root == NULL)
        return;
    stack<TreeNode*> s;
    //pCur:当前访问节点，pLastVisit:上次访问节点
    TreeNode* pCur, *pLastVisit;

    pCur = root;
    pLastVisit = NULL;
    //先把pCur移动到左子树最下边
    while (pCur)
    {
        s.push(pCur);
        pCur = pCur->left;
    }
    while (!s.empty())
    {
        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
        pCur = s.top();
        s.pop();
        //一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (pCur->right == NULL || pCur->right == pLastVisit)
        {
            cout << pCur->val <<  " ";
            //修改最近被访问的节点
            pLastVisit = pCur;
        }
        /*这里的else语句可换成带条件的else if:
        else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
        */
        else
        {
            //根节点再次入栈
            s.push(pCur);
            //进入右子树，且可肯定右子树一定不为空
            pCur = pCur->right;
            while (pCur)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
        }
    }
    cout << endl;
}

enum Tag{left,right};
//自定义新的类型，把二叉树节点和标记封装在一起
typedef struct
{
    TreeNode* node;
    Tag tag;
} TagNode;
//后序遍历
void postOrderWithoutRecursion2(TreeNode* root)
{
    if (root == NULL)
        return;
    stack<TagNode> s;
    TagNode tagnode;
    TreeNode* p = root;
    while (!s.empty() || p)
    {
        while (p)
        {
            tagnode.node = p;
            //该节点的左子树被访问过
            tagnode.tag = Tag::left;
            s.push(tagnode);
            p = p->left;
        }
        tagnode = s.top();
        s.pop();
        //左子树被访问过，则还需进入右子树
        if (tagnode.tag == Tag::left)
        {
            //置换标记
            tagnode.tag = Tag::right;
            //再次入栈
            s.push(tagnode);
            p = tagnode.node;
            //进入右子树
            p = p->right;
        }
        else//右子树已被访问过，则可访问当前节点
        {
            cout << (tagnode.node)->val << " ";
            //置空，再次出栈(这一步是理解的难点)
            p = NULL;
        }
    }
    cout << endl;
}

void postOrder(TreeNode *root)
{
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main(int argc, const char * argv[]) {
    /**
                    6
            2             8
        0      4       7     9
              3  5
     
     */
    
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
    
    inOrderWithoutRecursion(root);
    inOrderWithoutRecursion2(root);
    inOrder(root);
    cout << endl;
    preOrderWithoutRecursion(root);
    preOrderWithoutRecursion2(root);
    preOrderWithoutRecursion3(root);
    preOrder(root);
    cout << endl;
    postOrderWithoutRecursion(root);
    postOrderWithoutRecursion2(root);
    postOrder(root);
    cout << endl;
    
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    free(node8);
    
    return 0;
}
