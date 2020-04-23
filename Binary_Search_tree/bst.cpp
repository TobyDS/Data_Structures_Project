/*H**********************************************************************
* FILENAME :        bst.cpp
*
* DESCRIPTION :
*       File contains implementation for binary search tree     
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/
#include "bst.hpp"

using namespace std;

/*
 *  Function:  bst
 * --------------------
 *  Constructs an empty binary search tree
 * 
 *  returns: none
*/
bst::bst()
{
    head = NULL;
}

void delete_postorder(Node* n)
{
    if(n==NULL) return;
    delete_postorder(n->leftChild);
    delete_postorder(n->rightChild);
    delete n;
    return;
}

/*
 *  Function:  ~bst
 * --------------------
 *  Deconstructs a binary search tree
 * 
 *  returns: none
*/
bst::~bst() // TODO
{
    delete_postorder(head);
    return;
}

/*
 *  Function:  addNode
 * --------------------
 *  Adds node with key into bst
 * 
 *  key: the key to give inserted node
 * 
 *  returns: none
*/
void bst::addNode(int key)
{
    if (head == NULL)
    {
        Node *n = new Node;
        n->key = key;
        head = n;
        return;
    }
    Node *p = head;

    while (true)
    {
        if (key > head->key)
        {
            if (p->rightChild == NULL)
            {
                Node *n = new Node;
                n->key = key;
                p->rightChild = n;
                return;
            }
            p = p->rightChild;
        }
        else if (key < head->key)
        {
            if (p->leftChild == NULL)
            {
                Node *n = new Node;
                n->key = key;
                p->leftChild = n;
                return;
            }
            p = p->leftChild;
        }
    }
}

/*
 *  Function: search_key
 * ---------------------
 *  Searches for key in the tree
 * 
 *  key: the key to search for
 * 
 *  returns: to the Node with given key 
 *           or NULL if not found
*/
Node* bst::searchKey(int key)
{
    Node *traverseNode = head;

    while (traverseNode != NULL)
    {
        if (traverseNode->key == key)
        {
            return traverseNode;
        }
        else if (key > traverseNode->key)
        {
            traverseNode = traverseNode->rightChild;
        }
        else if (key < traverseNode->key)
        {
            traverseNode = traverseNode->leftChild;
        }
    }
    return NULL;
}



