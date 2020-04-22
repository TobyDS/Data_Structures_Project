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