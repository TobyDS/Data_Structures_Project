/*H**********************************************************************
* FILENAME :        driver.cpp
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
#include <chrono>
#include <iomanip>
#include "ll.hpp"

using namespace std;

int main()
{
    LinkedList l;
    l.printLL();

    auto start = chrono::high_resolution_clock::now();
    l.insertNode(NULL,39821);
    l.insertNode(l.searchLL(39821), 143591);
    l.insertNode(l.searchLL(143591), 57518);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Insertion time: " << time_taken << fixed << setprecision(9) << " sec" << endl;

    l.printLL();
    l.searchLL(1);

    return 0;
}
