#include <iostream>

#include "binary_search_tree.cpp"

using std::cout;
using std::endl;

int main() {

    BinarySearchTree bst;

    // Remove a number when there are no numbers in the tree
    bst.remove(20);
    cout<<endl;

    // Add numbers to the tree
    bst.add(20);
    bst.add(40);
    bst.add(10);
    bst.add(8);
    bst.add(9);
    bst.add(15);
    bst.add(9);
    bst.add(30);
    bst.add(25);
    bst.add(27);
    bst.add(28);
    bst.add(1);

    // Add a duplicate number
    bst.add(20);
    bst.add(40);



    // Display the tree numbers in order traversal (Ascending)
    cout << "test traversal:" << endl;
    bst.in_order_traversal();
    cout << endl;
    cout << endl;

    // Search for a number in the tree
    cout << "search for a number that is in the tree (20) will return a 1:  "  << bst.search(20) << endl;
    cout << endl;

    // Remove a number in the tree
    bst.remove(1);
    cout << "tree after removing number 1: ";
    bst.in_order_traversal(); 
    cout << endl << endl; 

    // Try to search for the number that was removed from the tree
    cout << "search for a number that is not in the tree (1) will return a 0:  "  << bst.search(1) << endl << endl;

    // Remove a number that it is not in the tree
    // Should not change the tree
    bst.in_order_traversal();
    cout << endl;
    bst.remove(3);
    cout << " so tree has not change as you can see below: " << endl;
    bst.in_order_traversal();
    cout << endl << endl;

    // Remove a number that the successor has a node to the right of it
    bst.remove(10);
    cout << "tree after removing 10: ";
    bst.in_order_traversal();
    cout << endl << endl;

    // Remove a number whose successor is to the right of it 
    bst.remove(27);
    cout << "tree after removing 27: ";
    bst.in_order_traversal();
    cout << endl << endl;
        
    return 0;
}