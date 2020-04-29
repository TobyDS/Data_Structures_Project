/*H**********************************************************************
* FILENAME :        bst.hpp
*
* DESCRIPTION :
*       File contains class definition for binary search tree
*       File contains Node struct definition 
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *leftChild = NULL;
    Node *rightChild = NULL;
};

class bst
{
private:
    Node *root; //Pointer to the root of BST

public:
    bst();  // Binary Search Tree Constructor
    ~bst(); // Binary Search Tree Deconstructor
    // Member Functions
    void addNode(int key);    // Inserts a node into BST
    Node *searchKey(int key); // Searches BST for a Node
    void printInOrder();      // Print BST in order
};

#endif