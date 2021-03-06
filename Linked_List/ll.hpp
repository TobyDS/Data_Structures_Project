/*H**********************************************************************
* FILENAME :        ll.hpp
*
* DESCRIPTION :
*       File contains class definition for linked list
*       File contains Node struct definition 
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/

#ifndef LL_HPP
#define LL_HPP

#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *next;
};

class LinkedList
{
private:
    Node *head; // pointer to head of linked list

public:
    LinkedList();  // Linked List Constructor
    ~LinkedList(); // Linked List Deconstructor
    // Member Functions
    void insertNode(Node *, int); // Inserts a single node
    Node *searchLL(int);          // Searches ll for a Node
    void printLL();               // Prints the contense of LL
};

#endif