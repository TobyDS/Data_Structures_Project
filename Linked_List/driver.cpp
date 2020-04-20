/*H**********************************************************************
* FILENAME :        ll.cpp
*
* DESCRIPTION :
*       File tests linked list class
*
* NOTES :
* 
* AUTHORS : Toby Dixon Smith & Vinicius Pelissari     START DATE : 20 Apr 20
*
*H*/

#include <iostream>
#include "ll.hpp"

using namespace std;

int main()
{
    LinkedList l;
    l.printLL();
    l.insertNode(NULL,39821);
    l.insertNode(l.searchLL(39821), 143591);
    l.insertNode(l.searchLL(143591), 57518);
    l.printLL();
    l.searchLL(1);

    return 0;
}
