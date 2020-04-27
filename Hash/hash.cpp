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
node* HashTable::createNode(int key, node* next)
{
    node* n = new node;
    n->key = key;
    n->next = next;
    return n;
}

HashTable::HashTable(int bsize)
{
    node* *a = new node[bsize];

    table = a;

    tableSize = bsize;

    for(int i = 0; i<tableSize ; i++)
    {
        table[i] = NULL;
    }
    return;
}

HashTable::~HashTable() //TODO
{

}

/*
bool HashTable::insertItem(int key) //linear probing
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
        numOfcolision++;
    }
    return true;
}*/

/*node* HashTable::searchItem(int key)//linear probing search
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
}*/

/*bool HashTable::insertItem(int key) //quadratic probing
{
    int idx;
    idx = key%tableSize;
    int i = 1;
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
        numOfcolision++;
    }

    return true;
}*/

node* HashTable::searchItem(int key)//quadratic probing search
{
    unsigned int idx = key%tableSize;
    int i = 1;
    while(table[idx%tableSize]!=NULL&&table[idx%tableSize]->key!=key)
    {
        idx+=i^2;
        if(table[idx]->key==key)
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
}

/*bool HashTable::insertItem(int key) //Chaining
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
        numOfcolision++;
        return true;
    }

    table[idx] = createNode(key,NULL);

    return true;
}*/