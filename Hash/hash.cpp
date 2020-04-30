/*H**********************************************************************
* FILENAME :        hash.cpp
*
* DESCRIPTION :
*       File contains implementation for Hash Table class
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 26 Apr 20
*
*H*/

#include <iostream>
#include "hash.hpp"

//Class Functions

/*
 *  Function:  createNode
 * --------------------
 *  Creates a node in the heap
 * 
 *  key and next: node parameters
 * 
 *  returns: pointer to created node
*/
node* HashTable::createNode(int key, node* next)
{
    node* n = new node;
    n->key = key;
    n->next = next;
    return n;
}

/*
 *  Function:  HashTable 
 * --------------------
 *  Creates a HashTable
 * 
 *  bsize: size of the table
 * 
 *  returns: none
*/
HashTable::HashTable(int bsize)
{
    node* *a = new node*[bsize];

    table = a;

    tableSize = bsize;

    for(int i = 0; i<tableSize ; i++)
    {
        table[i] = NULL;
    }
    return;
}

/*
 *  Function:  ~HashTable 
 * --------------------
 *  Deconstruct a HashTable
 * 
 *  returns: none
*/
HashTable::~HashTable()
{
    node *n, *next;
    for(int i = 0; i<tableSize; i++)
    {
        n = table[i];
        while (n!=NULL)
        {
            next = n->next;
            delete n;
            n=next;
        }
    }

    delete [] table;
    return;
}

/*
 *  Function:   insertItemLinear
 * --------------------
 *  Inserts a key into HashTable using Linear Collision resolution
 * 
 *  key: value to be inserted
 * 
 *  returns: true if successfull, false if not
*/
bool HashTable::insertItemLinear(int key)
{
    int idx;
    idx = key%tableSize;
    int initial = idx;
    while(table[idx]!=NULL)
    {
        idx++;
        if(idx>=tableSize)
        {
            idx=0;
        }
        if(idx==initial)
        {
            return false;
        }
    }
    table[idx]= createNode(key,NULL);

    if(idx!=initial)
    {
        numOfCollision++;
    }
    return true;
}

/*
 *  Function:   searchItemLinear
 * --------------------
 *  Searches a key in the HashTable considering Linear Collision resolution was used
 * 
 *  key: value to be searched
 * 
 *  returns: pointer to key if successful or NULL if not found
*/
node* HashTable::searchItemLinear(int key)
{
    int idx = key%tableSize;
    int initial = idx;
    while(table[idx]!=NULL&&table[idx]->key!=key)
    {
        idx++;
        if(idx>=tableSize)
        {
            idx = 0;
        }
        if(initial==idx)
        {
            return NULL;
        }
        if(table[idx]->key==key)
        {
            return table[idx]; 
        }
    }
    if(table[idx]==NULL)
    {
        return NULL;
    }
    if(table[idx]->key==key)
    {
        return table[idx];
    }
    return NULL;
}

/*
 *  Function:   insertItemQuadratic
 * --------------------
 *  Inserts a key into HashTable using Quadratic Collision resolution
 * 
 *  key: value to be inserted
 * 
 *  returns: true if successfull, false if not
*/
bool HashTable::insertItemQuadratic(int key)
{
    int idx;
    idx = key%tableSize;
    int i = 1;
    int initial =idx;
    while(table[idx%tableSize]!=NULL)
    {
        idx+= i^2;
        if(i==tableSize)
        {
            return false;
        }
        i++;
    }

    table[idx%tableSize]= createNode(key,NULL);

    if(idx!=initial)
    {
        numOfCollision++;
    }

    return true;
}

/*
 *  Function:   searchItemQuadratic
 * --------------------
 *  Searches a key in the HashTable considering Quadratic Collision resolution was used
 * 
 *  key: value to be searched
 * 
 *  returns: pointer to key if successful or NULL if not found
*/
node* HashTable::searchItemQuadratic(int key)
{
    unsigned int idx = key%tableSize;
    int i = 1;
    while(table[idx%tableSize]!=NULL&&table[idx%tableSize]->key!=key)
    {
        idx+=i^2;
        if(table[idx%tableSize]->key==key)
        {
            return table[idx%tableSize]; 
        }
        i++;
        if(i>tableSize)
        {
            return NULL;
        }
    }
    if(table[idx%tableSize]==NULL)
    {
        return NULL;
    }
    if(table[idx%tableSize]->key==key)
    {
        return table[idx];
    }
    return NULL;
}

/*
 *  Function:   insertItemChain
 * --------------------
 *  Inserts a key into HashTable using Chaining Collision resolution
 * 
 *  key: value to be inserted
 * 
 *  returns: true if successfull, false if not
*/
bool HashTable::insertItemChain(int key)
{
    int idx;
    idx = key%tableSize;
    if(table[idx]!=NULL)
    {
        node* n= table[idx];
        while(n->next!=NULL)
        {
            n=n->next;
        }
        node* newNode = createNode(key,NULL);
        n->next = newNode;
        numOfCollision++;
        return true;
    }

    table[idx] = createNode(key,NULL);

    return true;
}

/*
 *  Function:   searchItemChain
 * --------------------
 *  Searches a key in the HashTable considering Chaining Collision resolution was used
 * 
 *  key: value to be searched
 * 
 *  returns: pointer to key if successful or NULL if not found
*/
node* HashTable::searchItemChain(int key)
{
    unsigned int idx = key%tableSize;
    node* n = table[idx];
    while(n!=NULL&&n->key!=key)
    {
        if(n->next==NULL)
        {
            return NULL;
        }
        n=n->next;
    }
    if(n==NULL)
    {
        return NULL;
    }
    if(n->key==key)
    {
        return n;
    }
    return NULL;
}