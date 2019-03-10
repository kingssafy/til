#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

BinaryTree::BinaryTree(TreeNode* initialRoot) {
   root = initialRoot; 
}

void BinaryTree::print(void) {
    printHelper(root);
}

void BinaryTree::printHelper(TreeNode* node) {
    if (node != NULL) {
        cout << node->data << endl;
        printHelper(node->left);
        printHelper(node->right);
    }
}
bool BinaryTree::contains(int value) {
    return contains(root, value);
}

bool BinaryTree::contains(TreeNode* node, int value) {
    //TODO 
    if (node == NULL) {
        return false;
    } else if (node->data == value) {
        return true;
    } else {
        return contains(node->left, value) || contains(node->right, value);
    }
}

void BinaryTree::printSideways() {
    printSideways(root, "");
}
void BinaryTree::printSideways(TreeNode* node, string indent="") {
    // right subtree, then "me", then left subtree
    // 1) indentation
    // 2) basecase
    if (node != NULL) {
        printSideways(node->right, indent + "    ");
        cout << indent << node->data << endl;
        printSideways(node->left, indent + "    ");
    }

}

