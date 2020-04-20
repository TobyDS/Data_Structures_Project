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

#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node * next;
};

class LinkedList
{
    private:
        Node* head; // pointer to head of linked list

    public:

};