#include <iostream>

#include "binary_search_tree.h"

using std::cout;
using std::endl;

// Initializes the binary search tree under the premises of the class defined in the binary_search_tree.h file
BinarySearchTree::BinarySearchTree() {
    root = nullptr; // initializes the tree empty by setting the root to nullptr
}

void BinarySearchTree::add(int new_value) {
    // create new node
    BinaryNode *new_node = new BinaryNode{new_value, nullptr, nullptr};

    if(root == nullptr) {
        // assign root to that node
        root = new_node;
    } else {
        // find where it goes
        BinaryNode *current = root;
        BinaryNode *parent = nullptr;
        while(current != nullptr) {
            parent = current;
            if(new_value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        // update parent pointer
        if(new_value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}

void BinarySearchTree::in_order_traversal() {
    in_order_traversal_helper(root);
}

void BinarySearchTree::in_order_traversal_helper(BinaryNode *current) {
    if(current != nullptr) {
        // go left
        in_order_traversal_helper(current->left);
        // visit
        cout << current->value << endl;
        // go right
        in_order_traversal_helper(current->right);
    }
}