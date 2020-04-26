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
    root = NULL;
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
bst::~bst()
{
    delete_postorder(root);
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
    if (root == NULL)
    {
        Node *n = new Node;
        n->key = key;
        root = n;
        return;
    }
    Node *p = root;

    while (true)
    {
        if (key > root->key)
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
        else if (key < root->key)
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
    Node *traverseNode = root;

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

void inOrder(Node *curr)
{
    if(curr == NULL)
    {
        return;
    }
    inOrder(curr->leftChild);
    cout << curr->key << " ";
    inOrder(curr->rightChild);
}

void bst::printInOrder()
{
    inOrder(root);
    cout << endl;
}

