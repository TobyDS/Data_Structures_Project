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

/* 
 *  Function:  insertIntoLL
 * --------------------
 *  Inserts data from an array into a linked list
 * 
 *  l: a linked list to be inserted into
 *  insertData: an array of ints to be inserted into the linked list
 *  startIndex: the index in the array to start inserting at
 *  numToInsert: the number of elements to insert into the linked list
 * 
 *  returns: nothing
*/
void insertIntoLL(LinkedList &l, int insertData[], int startIndex, int numToInsert)
{
    for (int i = startIndex; i < startIndex + numToInsert; i++) // Insert numbers form start index to end index
    {
        l.insertNode(NULL, insertData[i]); // Insert all node as the start of the linked list.
    }
}

int main(int argc, char *argv[])
{
    LinkedList l;
    int MAX_ELEMENTS = 40000;   // There are 40,000 data entries in CSVs
    int testData[MAX_ELEMENTS]; // Contains all test data
    double insert[400];         // Contains average time taken to insert an element (seconds)
    double search[400];         // Contains times taken to search elements (seconds)

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
            // INSERTION INTO LL AND TIMING CALCULATION
            for (int numEntries = 0; numEntries < MAX_ELEMENTS; numEntries += 100)
            {
                auto start = chrono::high_resolution_clock::now();                                  // Start clock
                insertIntoLL(l, testData, numEntries, 100);                                         // Insert 100 entries
                auto end = chrono::high_resolution_clock::now();                                    // Stop the clock
                double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // Calculate time taken in nano seconds
                timeTaken *= 1e-9;                                                                  // Convert from nano seconds into seconds
                double averageTimeTaken = timeTaken / 100;                                          // Find average entry time
                insert[numEntries / 100] = averageTimeTaken;                                        // Log time taken for average entry
                
                if(numEntries % 4000 == 0) // Print a 10 entries as test
                {
                    cout << "Average insertion time: " << averageTimeTaken*1e9 << setprecision(4) << " nanosec" << endl;
                }
            }
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
        cerr << "Error: incorrect number of args. Please refer to usage" << endl;
        cout << endl;
        printUsage();
    }

    return 0;
}
