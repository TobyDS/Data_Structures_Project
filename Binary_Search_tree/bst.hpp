#include <iostream>

using namespace std;

typedef struct _Node
{
    int key;    
    Node* left = NULL;
    Node* right = NULL;
}Node;

class bst
{
    private:
    Node* head; //Pointer to the root of BST

    public:
    bst();
    ~bst();
    void add_node(int key);

};