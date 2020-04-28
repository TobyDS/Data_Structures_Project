#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numOfCollision = 0;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);  // Constructor
    ~HashTable();  // Deconstructor

    // inserts a key into hash table
    bool insertItemLinear(int key);
    bool insertItemQuadratic(int key);
    bool insertItemChain(int key);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    int getNumOfCollision();

    node* searchItemLinear(int key);
    node* searchItemQuadratic(int key);
    node* searchItemChain(int key);
};

#endif
