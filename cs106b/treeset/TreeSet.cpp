#include "TreeSet.h"






void TreeSet::add(int value) {
    if (root == NULL) {
        root = new TreeNode(value);
    } else {
        add(root, value)
    }
}

void TreeSet::add(TreeNode* node, int value) {
    if (node == NULL) {
        node = new TreeNode(value);
    } else if (value < node->data) {
        if (node->left == NULL) {
            node->left = new TreeNode(value); // This works
        } else {

        }
    }
}

void TreeSet::add(TreeNode* node, int value) {  //This doesn't work until you change the function header to
    if (node == NULL) {  // add(TreeNode*& node, int value)
        node = new TreeNode(value);
    } else if (value < node->data) {
        add(node->right, value);
    } else if (value > node->data) {
        add(node->left, value);
    }
}

int TreeSet::getMin() const {
    //TODO
    if (root == NULL) {
        throw ":-(";
    } else {
        return getMin(root);
    }
    
}

int TreeSet::getMin(TreeNode* node) const {
    if (node->left == NULL) {
        return node->data;
    } else {
        return getMin(node->left);
    }
}

void TreeSet::remove(int value) {
    remove(root, value);
}

void TreeSet::remove(TreeNode*& node, int value) {
    if (node == NULL) {
        //?
    } else {
        if (value < node->data) {
            remove(node->left, value);
        } else if (value > node->data) {
            remove(node->right, value);
        } else {
            // node->data == value
            // i am node to remove 
            TreeNode* trash = NULL;
            if (node->left ==NULL && node->right == NULL) {
                trash = node;
                node = NULL;
            } else if (node->right == NULL) {
                trash = node;
                node = node->left;
            } else if (node->left == NULL) {
                trash = node;
                node = node->right;
            } else {
                int newData = getMin(node->right);
                node->data = newData;
                remove(node->right, newData); //minimum means it has no left child so it will land one of three cases
            }
            if (trash != NULL) {
                delete trash;
            }
        }
    }
}
