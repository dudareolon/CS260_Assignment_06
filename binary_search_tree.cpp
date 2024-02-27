#include <iostream>

#include "binary_search_tree.h"

using std::cout;
using std::endl;

// Initializes the binary search tree under the premises of the class defined in the binary_search_tree.h file
BinarySearchTree::BinarySearchTree() {
    root = nullptr; // initializes the tree empty by setting the root to nullptr
}

// This function adds a node in the tree at the correct location
void BinarySearchTree::add(int new_value) {
    // create a new node that takes in the new_value but its right and left pointer are to nothing
    BinaryNode *new_node = new BinaryNode{new_value, nullptr, nullptr};

    // if the tree is empty
    if(root == nullptr) {
        // assign root to that node
        root = new_node; // new node because the top of the tree and the only node currently at the tree
    } else {
        // will need to create two pointers
        // a current pointer that stores the address of the node we are analyzing during the iteration through the tree
        // a parent pointer which indicates the address of the parent node of the node we are analyzing 
        BinaryNode *current = root; // start iteration at the beginning of the tree
        BinaryNode *parent = nullptr; // start the parent pointer one step behind the current pointer

        // repeat the while loop until the current pointer reaches the end of the tree, aka nullptr
        while(current != nullptr) {
            parent = current; // update the parent pointer to the next step which will be the current node we are analyzing

            // decide if we need to go to the right or to the left of the node we are analyzing
            // if the value we want to add is smaller or equal to the value we are analyzing then make it go to the left 
            if(new_value <= current->value) {
                current = current->left;
            } else { // if the value we want to add is bigger than make it go to the right of the node we are analyzing
                current = current->right;
            }
        }
        // with the same rules of going to the left or to the right we will update the parent pointer so new node is fully inserted in the tree
        if(new_value <= parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }
}


// This function searches if a value is present (returns 1) or not (returns 0) in the tree without removing the value
bool BinarySearchTree::search(int value){
    // result with a safe default value
    bool result = false;
    // start current at root
    BinaryNode *current = root;
    //check for nullptr
    while(current != nullptr) {
        // check current->value
        if(value == current->value) {
            result = true;
            break;
        } else if(value < current->value) {
        // move based on being less than or greater than root->value
            current = current->left;
        } else {
            current = current->right;
        }

    }

    return result;
}

int BinarySearchTree::remove(int old_value) {
    BinaryNode* parent = nullptr;
    BinaryNode* current = root;

    // Search for the node to be removed and keep track of its parent
    while (current != nullptr && current->value != old_value) {
        parent = current;
        if (old_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the value is not found, return -1
    if (current == nullptr) {
        cout << "the number entered is not in the tree" << endl;
        return -1;
    }

    // Case 1: Node to be removed has no children or one child
    if (current->left == nullptr || current->right == nullptr) {
        BinaryNode* temp = nullptr;
        if (current->left != nullptr){
            temp = current->left;
        } else if (current -> right != nullptr) {
            temp = current->right;
        } else {
            if (parent->left == current){
                parent->left = nullptr;
            } else if (parent->right == current){
                parent->right = nullptr;
            }
        }      

        if (parent->left == current) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
        delete current;
    }
    // Case 3: Node to be removed has two children
    else {
        BinaryNode* successorParent = current;
        BinaryNode* successor = current->right;
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        current->value = successor->value;

       if (successorParent == current) {
            current->right = successor->right;
        } else {
            // this takes into consideration that even though the successor points to nullptr on its left, there might still be a node on its right
            // if there is a node on its right then that node will become the left side of the successor parent, 
            // since it is the only thing left on the left branch of the successor parent
            successorParent->left = successor->right;
        }

        delete successor;
    }
    return 0;
}


void BinarySearchTree::in_order_traversal() {
    in_order_traversal_helper(root);
}

void BinarySearchTree::in_order_traversal_helper(BinaryNode *current) {
    if(current != nullptr) {
        // go left
        in_order_traversal_helper(current->left);
        // visit
        cout << current->value << " ";
        // go right
        in_order_traversal_helper(current->right);
    }
}