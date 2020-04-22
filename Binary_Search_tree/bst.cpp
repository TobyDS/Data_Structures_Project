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

/*
 *  Function:  ~bst
 * --------------------
 *  Deconstructs a binary search tree
 * 
 *  returns: none
*/
bst::~bst() // TODO
{
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


/*
 *  Function: deleteNode
 * ----------------------
 * Deletes node with given key
 * 
 * key: the key that the deleted node will have
 * 
 * returns: 0 if successful and -1 if not
*/
int bst::deleteNode(int key)
{
    Node* n = this->searchKey(key);
    
    if(n==NULL) return -1;


}

//Function findParent is needed to make this functions work
//Also they need to be changed so they work with the function

Node* bst::findParent(int key)
{
    Node* 
}


void _removeMovieTree(TreeNode *tree)
{
    if(tree->leftChild==NULL&&tree->rightChild==NULL)
    {
        if(tree->parent->leftChild==tree)
            {
                tree->parent->leftChild = NULL;
                return;
            }
            else
            {
                tree->parent->rightChild = NULL;
                return;
            }
    }
    else if(tree->leftChild==NULL)
    {
        if(tree->parent->leftChild==tree)
            {
                tree->parent->leftChild = tree->rightChild;
                tree->rightChild->parent = tree->parent;
                return;
            }
            else
            {
                tree->parent->rightChild = tree->rightChild;
                tree->rightChild->parent = tree->parent;
                return;
            }
    }
    else if(tree->rightChild==NULL)
    {
        if(tree->parent->leftChild==tree)
            {
                tree->parent->leftChild = tree->leftChild;
                tree->leftChild->parent = tree->parent;
                return;
            }
            else
            {
                tree->parent->rightChild = tree->leftChild;
                tree->leftChild->parent = tree->parent;
                return;
            }
    }
    else
    {
        TreeNode *aux = tree->rightChild;
        while(aux->leftChild!=NULL)
        {
            aux = aux->leftChild;
        }
        _removeMovieTree(aux);
        aux->leftChild = tree->leftChild;
        aux->rightChild = tree->rightChild;
        aux->parent = tree->parent;
        if(aux->parent->leftChild==aux)
            {
                aux->parent->leftChild = aux;
                return;
            }
            else
            {
                aux->parent->rightChild = aux;
                return;
            }
    }
    
}

TreeNode* _removeMovieTreeRoot(TreeNode *tree) 
{
    if(tree->leftChild==NULL&&tree->rightChild==NULL)
    {
        return NULL;
    }
    else if(tree->leftChild==NULL)
    {
        tree->rightChild->parent = tree->parent;
        return tree->rightChild;
    }
    else if(tree->rightChild==NULL)
    {
        tree->leftChild->parent = tree->parent;
        return tree->leftChild;
    }
    else
    {
        TreeNode *aux = tree->rightChild;
        while(aux->leftChild!=NULL)
        {
            aux = aux->leftChild;
        }
        _removeMovieTree(aux);
        aux->leftChild = tree->leftChild;
        aux->leftChild->parent = aux;
        aux->rightChild = tree->rightChild;
        aux->rightChild->parent = aux;
        aux->parent = NULL;
        return aux;
    } 
}
