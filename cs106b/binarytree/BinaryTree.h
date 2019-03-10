#ifndef _BinaryTree_H
#define _BinaryTree_H
#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data,
            TreeNode* left = NULL,
            TreeNode* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    bool isLeaf(void) {
        return left == NULL & right == NULL;
    }
};


// A BinaryTree represents an entire binary tree of ints.
class BinaryTree {
    //members;
public:
    BinaryTree(TreeNode*);
    
    bool contains(int);
    void print();
    void printSideways();
private:
    TreeNode* root; // NULL for an empty tree
    void printHelper(TreeNode*);
    bool contains(TreeNode*, int);
    void printSideways(TreeNode*, string);

};


#endif
