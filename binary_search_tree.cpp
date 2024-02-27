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

// This function removes a value from the tree and relocates the other nodes in the tree to the correct location
int BinarySearchTree::remove(int old_value) {
    // The same way as in the add function we need to create two pointers. One pointer for the iteration that we will do through the list (current) 
    // and another pointer to store the parent node of the iteration node (parent)
    BinaryNode* parent = nullptr;
    BinaryNode* current = root;

    // Search for the node to be removed and keep track of its parent
    // The search will continue until it reaches the end of the tree (when current is nullptr)
    // or until the value of the node we are analyzing is the value we want to remove from the tree 
    while (current != nullptr && current->value != old_value) {

        // the parent pointer needs to be updated to the current pointer in order for the iteration to proceed
        parent = current;

        // the current pointer needs to be updated to its right value if the value we are looking for is bigger, or to its left value if the number we are looking for is smaller
        if (old_value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // If the value is not found, return -1
    if (current == nullptr) { // reaches the end of the tree
        cout << "the number entered is not in the tree" << endl;
        return -1;
    }

    // At this point we know what the node that needs to be removed is (stored in current)
    // And what the father of this node is and that needs to have one of its addresses updated (stored in parent)

    // Case 1: Node to be removed has no children or one child
    if (current->left == nullptr || current->right == nullptr) { 

        // create a new pointer called temp (short for temporary) to store the node we will need to move around until it is ready to go to its designated slot
        BinaryNode* temp = nullptr;

        // in the case of one child from the current node:
        // if the value that will be removed has a child to its left, then the child node value will be stored in temp
        if (current->left != nullptr){ 
            temp = current->left;
        } else if (current -> right != nullptr) { // the same will happen if the child of the node to be removed is in the right of it
            temp = current->right;
        } else {
            // this accounts for the case in which the node that needs to be removed has no kids
            // which would make the parent node either to the left or the right point to nullptr
            if (parent->left == current){
                parent->left = nullptr;
            } else if (parent->right == current){
                parent->right = nullptr;
            }
        }      

        // in the cases where there is one child, it will assign the child either to the right or to the left of its grandchild, as the parent node will be removed
        if (parent->left == current) {
            parent->left = temp;
        } else {
            parent->right = temp;
        }
    }
    // Case 2: Node to be removed has two children
    else {

        // Two new pointers need to be created
        // one for the successor which is the node with the smallest value in the right subtree of the current node. 
        // the other for the successor parent, so the node that holds the address of the successor node
        BinaryNode* successorParent = current;
        BinaryNode* successor = current->right;

        // iterate through the entire tree to find the successor and the successor parent of the current node (node to be removed)
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }
        // the current value is replaced to being its successor value
        current->value = successor->value;

        // this takes into consideration that the successor might not be stored in the left address of its parent, because it might be the first value to the right of the current node
       if (successorParent == current) {
            current->right = successor->right;
        } else {
            // this takes into consideration that even though the successor points to nullptr on its left, there might still be a node on its right
            // if there is a node on its right then that node will become the left side of the successor parent, 
            // since it is the only thing left on the left branch of the successor parent
            successorParent->left = successor->right;
        }
    }
    return 0;
}

// Both functions below work together to print out the tree in order traversal from smaller to bigger number 
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