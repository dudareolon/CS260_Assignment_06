# CS260_Assignment_06
Binary search tree - Eduarda Reolon

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The goal of this assignment is to implement a binary search tree that includes:
- nodes to store values,
- an add function that adds a new value in the appropriate location based on our ordering rules,
- a remove function that finds and removes a value and then picks an appropriate replacement node,
- and at least one tree traversal function

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Design:

There will be 4 files in my program:

............................................................................................................................................................................................................

*binary_node.h*: this file will contain the structure that will define what are the properties of each node in the binary search tree. This is a binary node:

  ![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/f524f40a-0bd9-40d7-9630-c13b9757ab36)

It is composed of:

        - the integer value stored in the node
        
        - the adress of the node to the right of it (will point to nullptr if there are no nodes to the right of it)
        
        - the adress of the node to the left of it (will point to nullptr if there are no nodes to the left of it)


............................................................................................................................................................................................................

*binary_search_tree.h*: this file will define what the BinarySearchTree class is. It will privately initialze the initial node of the tree and the tree itself, and it will define all functions that will be under the class. These functions are:

        - Add (an integer value) -> Return nothing;
  
        - Remove (an integer value) -> Return the value if it was successfully removed otherwise return an error message;
  
        - Search (an integer value) -> Retunr true or false;

        - Print_in_order_traversal(no input needed) -> return all the numbers in the binary tree in order traversal.

This is a visual example of what a binary tree is spposed to look like:

![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/0124acf4-2612-49b6-bf27-b68db5ae731b)

Being that on the class definition we are going to start by deifining the circle with the number 40 to be the ROOT of the tree, since it will always be the first comparision done in the tree and since it is the highest one in order. 


............................................................................................................................................................................................................

*binary_search_tree.cpp*: This is the file where the actual code for each one of the functions will be done. The first step of this file is to create a binary tree under the class defined in the binary_search_tree.h file and make sure that the root of the tree is initially pointing to nullptr (meaning the tree is empty).

The functions defined in this file are:

- voide add(int new_value); // add function that takes a new input and returns nothing

  The add function will initially check if the tree is empty, by checking if the root is pointing to nullptr. If it is then it will store the new value in the root poition.
  If the tree is not empty then it will compare the new value to the value that is in the root, if the new value is bigger than the value in the root then we will update the pointer to point to the address on the right of the root, if it is smaller or equal to the value in the root then the pointer will be updated to point to the left adress of the root.  
  
- int remove(int old_value); // remove function that takes in an old input and returns this old input

- bool search(int value); // search function that finds the input value and returns if it is true or not that value is in the tree

- void print_in_order_traversal(); // prints out all the values of the tree in order traversal

  
............................................................................................................................................................................................................

*main.cpp*:
