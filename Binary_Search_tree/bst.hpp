<<<<<<< HEAD
=======
/*H**********************************************************************
* FILENAME :        bst.hpp
*
* DESCRIPTION :
*       File contains class definition for binary search tree
*       File contains Node struct definition 
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/

>>>>>>> caa23a6664e7991ac3dd1731b078e1b76d7f2f31
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