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
#include <sstream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include "ll.hpp"

using namespace std;

/*
 *  Function:  printUsage
 * --------------------
 *  Prints the correct usage for the program
 * 
 *  returns: usage message
*/
void printUsage()
{
    cerr << "USAGE: ./driver.out [Data Set: A or B]" << endl;
}

/* 
 *  Function:  readData
 * --------------------
 *  Reads contense of CSV into an array
 * 
 *  testData: array to be filled
 *  dataPath: gives the path to the dataFile
 * 
 *  returns: error if file can't be opened
*/
void readData(int testData[], string dataPath)
{
    fstream inputFile;        // Create fstream object
    inputFile.open(dataPath); // Open the data file
    if (inputFile.is_open())  // If the file opens read it
    {
        string line;
        while (getline(inputFile, line)) // Get every line
        {
            string entry; // Stores single number
            stringstream lineStream(line);
            int size = 0;
            while (getline(lineStream, entry, ',')) // Get each entry
            {
                testData[size] = stoi(entry); // Read to array
                size++;
            }
        }
    }
    else
    {
        cerr << "Error: file not opened correctly" << endl;
    }
}

int main(int argc, char *argv[])
{
    LinkedList l;
    int MAX_ELEMENTS = 40000;   // There are 40,000 data entries in CSVs
    int testData[MAX_ELEMENTS]; // Contains all test data
    double insert[400];         // Contains times taken to insert 100 elements
    double search[400];         // Contains times taken to search elements

    if (argc == 2) // Correct number of command line args
    {
        string setName = argv[1]; // Name of the data set to be used, A or B
        if (setName == "A" || setName == "B")
        {
            string dataPath; // Stores path for data set to be used
            if (setName == "A")
            {
                dataPath = "../Data/dataSetA.csv";
            }
            else if (setName == "B")
            {
                dataPath = "../Data/dataSetB.csv";
            }
            readData(testData, dataPath);
        }
        else // Incorrect name for data set
        {
            cerr << "Error: Must choose A or B. Please refere to usage" << endl;
            cout << endl;
            printUsage();
        }
    }
    else // Incorrect number of command line args
    {
        cerr << "Error: not enough args. Please refer to usage" << endl;
        cout << endl;
        printUsage();
    }

    return 0;
}
