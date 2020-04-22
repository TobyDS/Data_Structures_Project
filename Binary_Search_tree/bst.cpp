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

bst::bst()
{
    head = NULL;
}

bst::~bst() //todo
{

}


/*
 *  Function:  add_node
 * --------------------
 *  Adds node with key to bst
 * 
 *  returns: none
*/
void bst::add_node(int key)
{
    if(head==NULL)
    {
        Node* n = new Node;
        n->key = key;
        head = n;
        return;
    }
    Node* p=head;

    while(1)
    {
        if(key>head->key)
        {
            if(p->right==NULL)
            {
                Node* n = new Node;
                n->key = key;
                p->right = n;
                return;
            }
            p=p->right;
        }
        else if(key<head->key)
        {
            if(p->left==NULL)
            {
                Node* n = new Node;
                n->key = key;
                p->left = n;
                return;
            }
            p=p->left;
        }
    }
}

/*
 *  Function: search_key
 * ---------------------
 *  Searches for key in the tree
 * 
 *  returns: address of Node with given key or NULL if not found
*/
Node* bst::search_key(int key)
{
    Node* traverse_Node = head;

    while(traverse_Node!=NULL)
    {
        if(traverse_Node->key==key)
        {
            return traverse_Node;
        }
        else if(key>traverse_Node->key)
        {
            traverse_Node = traverse_Node->right;
        }
        else if(key<traverse_Node->key)
        {
            traverse_Node = traverse_Node->left;
        }
    }
    return NULL;
}