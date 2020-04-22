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
    Node *head; //Pointer to the root of BST

public:
    bst();                     // Binary Search Tree Constructor : Done
    ~bst();                    // Binary Search Tree Deconstructor TODO
    void addNode(int key);    // Inserts a node into BST : Done, not tested
    Node *searchKey(int key); // Searches BST for a Node : Done, not tested
    int deleteNode(int key);  // Deletes a Node from BST : TODO
    void printTree();          // Print BST : Could be done for testing
};