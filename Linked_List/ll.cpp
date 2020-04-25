/*H**********************************************************************
* FILENAME :        ll.cpp
*
* DESCRIPTION :
*       File contains implementation for linked list class
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/

#include <iostream>
#include "ll.hpp"

using namespace std;

/*
 *  Function:  LinkedList
 * --------------------
 *  Constructs an empty linked list
 * 
 *  returns: none
*/
LinkedList::LinkedList()
{
    head = NULL;
}

/*
 *  Function:  ~LinkedList
 * --------------------
 *  Deconstructs a linked list
 * 
 *  returns: none
*/
LinkedList::~LinkedList()
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *current = head;
        Node *next;
        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
}

/*
 *  Function:  insertNode
 * --------------------
 *  Inserts a node into a linked list
 *  
 *  previous: the previous ll node
 *  key: the key of the node to be added
 * 
 *  returns: an error if the previous node can't be found
*/
void LinkedList::insertNode(Node *previous, int key)
{
    if (head == NULL)
    {
        Node *nn = new Node;
        nn->key = key;
        nn->next = NULL;
        head = nn;
    }
    else if (previous == NULL)
    {
        Node *nn = new Node;
        nn->key = key;
        nn->next = head;
        head = nn;
    }
    else
    {
        Node *nn = new Node;
        nn->key = key;
        Node *prevNext = new Node;
        prevNext = previous->next;
        previous->next = nn;
        nn->next = prevNext;
    }
}

/*
 *  Function:  searchLL
 * --------------------
 *  Finds a node within the linked list
 *  
 *  key: the key of the node to be found
 * 
 *  returns: the node with the given key
 *           or an error if the node is not found
*/
Node *LinkedList::searchLL(int key)
{
    Node *current = new Node;
    current = head;
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current;
        }
        current = current->next;
    }
    cout << "Error: Key not found" << endl;
    return NULL;
}

/*
 *  Function:  printLL
 * --------------------
 *  Prints the linked list
 * 
 *  returns: all the keys from the linked list
 *           or an error if list is empty
*/
void LinkedList::printLL()
{
    if (head == NULL)
    {
        cout << "Error: No items in list" << endl;
    }
    else
    {
        int total = 0;
        Node *current = new Node;
        current = head;
        cout << "Printing Linked List:" << endl;
        cout << "=====" << endl;
        while (current != NULL)
        {
            cout << current->key << endl;
            current = current->next;
            total++;
        }
        cout << "=====" << endl;
        cout << total << " total node(s)" << endl;
    }
}