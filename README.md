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

- *binary_node.h*: this file will contain the structure that will define what are the properties of each node in the binary search tree. This is a binary node:

  ![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/f524f40a-0bd9-40d7-9630-c13b9757ab36)

It is composed of:

        - the integer value stored in the node
        
        - the adress of the node to the right of it (will point to nullptr if there are no nodes to the right of it)
        
        - the adress of the node to the left of it (will point to nullptr if there are no nodes to the left of it)

        

- *binary_search_tree.h*: this file will define what the BinarySearchTree class is. It will privately initialze the initial node of the tree and the tree itself, and it will define all functions that will be under the class. These functions are:

        - Add (an integer value) -> Return nothing;
  
        - Remove (an integer value) -> Return the value if it was successfully removed otherwise return an error message;
  
        - Search (an integer value) -> Retunr true or false;

        - Print_in_order_traversal(no input needed) -> return all the numbers in the binary tree in order traversal.



- *binary_search_tree.cpp*:

- *main.cpp*:
