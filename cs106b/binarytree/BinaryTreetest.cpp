#include "BinaryTree.h"
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    TreeNode* node = new TreeNode(42);
    node->left = new TreeNode(59);
    node->right = new TreeNode(27);
    node->right->right = new TreeNode(86);
    BinaryTree tree(node);
    tree.print();
    cout << boolalpha << tree.contains(42) << endl;
    tree.printSideways();
    return 0;
}
