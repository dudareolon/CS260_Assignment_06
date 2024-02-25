#include "binary_node.h"

class BinarySearchTree {
    // this class defines what a binary search tree will be
    BinaryNode *root; // the initial node will point to the root address (top of the tree)

    void in_order_traversal_helper(BinaryNode *current);

    public:
        BinarySearchTree(); // initialize the binary search tree
        void add(int new_value); // add function that takes a new input and returns nothing
        int remove(int old_value); // remove function that takes in an old input and returns this old input
        bool search(int value); // search function that finds the input value and returns if it is true or not that value is in the tree
        void in_order_traversal();// prints out all the values of the tree in order traversal
};
