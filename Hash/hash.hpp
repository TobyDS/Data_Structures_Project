/*H**********************************************************************
* FILENAME :        hash.hpp
*
* DESCRIPTION :
*       File contains definition for Hash Table class
*       File contains node struct definition 
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 26 Apr 20
*
*H*/

#ifndef HASH_HPP
#define HASH_HPP

#include <string>

using namespace std;

struct node
{
    int key;
    struct node *next;
};

class HashTable
{
private:
    int tableSize; // No. of buckets (linked lists)
    node **table;  // Pointer to an array containing buckets
    int numOfCollision = 0;
    node *createNode(int key, node *next);

public:
    HashTable(int bsize); // Constructor
    ~HashTable();         // Deconstructor
    // Member Functions
    bool insertItemLinear(int key);     // Inserts a key into hash table using linear probing
    bool insertItemQuadratic(int key);  // Inserts a key into hash table using quadratic probing
    bool insertItemChain(int key);      // Inserts a key into hash table using chaining with a linked list
    node *searchItemLinear(int key);    // Search hash table with linear probing
    node *searchItemQuadratic(int key); // Search hash table with quadratic probing
    node *searchItemChain(int key);     // Search hash table with chaining
};

#endif
