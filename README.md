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

- void add(int new_value); // add function that takes a new input and returns nothing

  The first step of the add function is to create a new node for the new value that will be added. 

  Then the add function will check if the tree is empty, by checking if the root is pointing to nullptr. If it is then it will store the new value in the root poition.

   If the tree is not empty then it will compare the new value to the value that is in the root, if the new value is bigger than the value in the root then we will update the pointer to point to the address on the right of the root, if it is smaller or equal to the value in the root then the pointer will be updated to point to the left adress of the root.

  Now that the iteration pointer is pointing to a node on the second level and not to the root anymore, we will compare the new value to the value in the new node we are analyzing. Again, if the new value is smaller or equal to the value in the node we are analyzing, the iteration pointer will update to pointing to the left address stored in that binary node. The same way if the new value is bigger then the pointer will update to the right address of the node we are anlysizing.

   The code will stay repeating this system until it finds that the left or right address of the node it is analysizing is pointing to nullptr, and that will be where the new value must be inserted. To do that we will simply update the node we are analysizing left or right (depends on the case) pointer to point to the new node wse created.


:)  

  
- int remove(int old_value); // remove function that takes in an old input and returns this old input
  This function starts by creating two pointers. One that will iterate until finding the value we want to remove (will be started pointing at the root) and another pointer that will iterate until finding the parent node of the node we want to remove (will be started at nullptr). Now we have an iteration pointer and a parent of iteration pointer.
  Then we will search for the node to be removed and keep track of its parent by using a while loop. If the value we are looking for is smaller than the value of the node we are looking at, then we will move to the left address of the binary node we are looking at. If it bigger then we will look at the right address. If it is equal we will exit out of the loop.
  At this point of the code we already have the correct address for the iteration pointer (value we want to remove) and for the parent of the iteration pointer (parent node of the value we want to remove)
  If the value is not found (if iteration pointer is equal to nullptr which means it reached the end of the binary search tree), then an error message will display and return -1.

  Now there are two possible cases of what could be happening

   - Case 1: Either the left or the right pointer of the node we want to remove is nullptr (meaning that the node has no or has only one child node). If the node has no child, then just make its parent node right or left address (depending where the removed node is at) be pointing to nullptr. If the node has one child, store the child in a temporary pointer, and go to the parent of the node we want to remove, find if the node is on the right or left of its parent, and make the parent point to the removed node child. In other words, make the grandparent point to its grandchild because the parent was removed. 
  
    - Case 2: Both right and left pointer address of the node we want to remove are pointing to another node (meaning it has two children nodes). For this we are going to have to use the successor concept. Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of the input node. So, it is sometimes important to find next node in sorted order. In the picture below we can see that the inorder successor of 8 is 10, inorder successor of 10 is 12 and inorder successor of 14 is 20.
 
![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/87044e25-c0ca-4539-b071-bb1014c07e39)

      

  
  
:)


- bool search(int value); // search function that finds the input value and returns if it is true or not that value is in the tree

    This function will do the same thing as the add function, but it won't create a new node for the input value at the beginning and when it gets to nullptr it won't insert a new node, it will simply display that the input value was not found and return false. For this function also besides comparing if the inserted value is bigger or smaller it will also look if they are the same, because if they are the same then the system will return true.


:)


- void print_in_order_traversal(); // prints out all the values of the tree in order traversal

  This function will make what is in the picture below happen:

![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/a868d7a4-7c63-4e61-a6f3-266c7a3b4771)
  
  This function will turn the binary tree into a string list of all of the numbers in the tree in order from smaller to bigger. It is an in order traverse which means the code will go in the order left, visit, right, which means it will first check what is in the left address of the node, if there is something in the left it will keep checking until it gets to the leftmost node, then it visits the node, which means it prints its value, and then it checks the right side of that node, if there is nothing on the right node then it goes back up one level and visits on the node up a level. The picture below can beter explain how this works:

  ![image](https://github.com/dudareolon/CS260_Assignment_06/assets/102680672/c2454c93-883f-49ad-abbe-705f15edaa58)
  
The in order is indicated by the green dots. It repeats the same process of left, visit, right until all the nodes in the tree are visited and printed out, this version of traversing through the list outputs a numerical ascending list. 
  
............................................................................................................................................................................................................

*main.cpp*:
