/*H**********************************************************************
* FILENAME :        driver.cpp
*
* DESCRIPTION :
*       File tests Binary search Tree class
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
#include <time.h>
#include "bst.hpp"

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
void insertIntoBst(bst &l, int insertData[], int startIndex, int numToInsert) //change this
{
    for (int i = startIndex; i < startIndex + numToInsert; i++) // Insert numbers form start index to end index
    {
        b.addNode(NULL, insertData[i]); // Insert all node as the start of the linked list.
    }
}

/* 
 *  Function:  generateRandomInts
 * --------------------
 *  Populates an array with random integers bellow a given number
 * 
 *  randInts: an empty array to fill with random integers
 *  maximum: the maximum value that can be generated
 *  count: the number of ints to generate
 * 
 *  returns: nothing
*/
void generateRandomInt(int randInts[], int maximum, int count)
{
    for (int i = 0; i < count; i++)
    {
        int num = (rand() % (maximum + 1));
        randInts[i] = num;
    }
}

/* 
 *  Function:  generateCSV
 * --------------------
 *  Generates a CSV file to store results of insert and search
 * 
 *  insert: an array of doubles containing insert times in seconds
 *  search: an array of doubles containing search times in seconds
 *  count: the number of entries in insert and search
 *  setName: string of which set was tested
 * 
 *  returns: a CSV file containing the information
*/
void generateCSV(double insert[], double search[], int count, string setName)
{
    ofstream outputFile;
    if (setName == "A")
    {
        outputFile.open("Outputs/insert_search_performance_binary_search_tree_dataSetA.csv");
    }
    else if (setName == "B")
    {
        outputFile.open("Outputs/insert_search_performance_binary_search_tree_dataSetB.csv");
    }
    if (outputFile.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            outputFile << (i + 1) << "," << insert[i] << "," << search[i] << endl;
        }
        outputFile.close();
        cout << "=== Testing Compleate ===" << endl
             << endl;
        cout << "Find results in Outputs folder under the name:";
        if (setName == "A")
        {
            cout << "insert_search_performance_linked_list_dataSetA.csv" << endl;
        }
        else if (setName == "B")
        {
            cout << "insert_search_performance_linked_list_dataSetB.csv" << endl;
        }
        cout << "CSV structure: Iteration, insert time [s], search time[s]" << endl << endl;
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));                    // Use current time as seed for random generator
    bst b;                      // Create linked list object
    int MAX_ELEMENTS = 40000;          // There are 40,000 data entries in CSVs
    int testData[MAX_ELEMENTS];        // Contains all test data
    double insert[MAX_ELEMENTS / 100]; // Contains average time taken to insert an element (seconds)
    double search[MAX_ELEMENTS / 100]; // Contains times taken to search elements (seconds)

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
            cout << "=== Conducting test on data set : " << setName << " ===" << endl;
            // INSERTION INTO LL, SEARCHING LL AND TIME CALCULATION
            for (int numEntries = 0; numEntries < MAX_ELEMENTS; numEntries += 100)
            {
                // INSERTION
                auto start = chrono::high_resolution_clock::now();                                  // Start clock
                insertIntoBst(b, testData, numEntries, 100);                                        // Insert 100 entries
                auto end = chrono::high_resolution_clock::now();                                    // Stop the clock
                double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // Calculate time taken in nano seconds
                timeTaken *= 1e-9;                                                                  // Convert from nano seconds into seconds
                double averageTimeTaken = timeTaken / 100;                                          // Find average entry time
                insert[numEntries / 100] = averageTimeTaken;                                        // Log time taken for average entry
                // SEARCHING
                int randInts[100];
                generateRandomInt(randInts, numEntries + 99, 100); // Generate rand int for size of entries
                for (int i = 0; i < 100; i++)                      // Switch the index for the key to search for
                {
                    randInts[i] = testData[randInts[i]];
                }
                start = chrono::high_resolution_clock::now(); // Start clock
                for (int i = 0; i < 100; i++)                 // Loop through all 100 entries
                {
                    b.searchKey(randInts[i]); // Search for each randomly generated key
                }
                end = chrono::high_resolution_clock::now();                                  // Stop clock
                timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); // Calculate time taken in nano seconds
                timeTaken *= 1e-9;                                                           // Convert from nano seconds into seconds
                averageTimeTaken = timeTaken / 100;                                          // Find average entry time
                search[numEntries / 100] = averageTimeTaken;                                 // Log time taken to search

                // TEST PRINT
                // if (numEntries % (MAX_ELEMENTS / 5) == 0) // Print 10 average times as test
                // {
                //     cout << fixed << setprecision(9);
                //     cout << "Average insertion time: " << insert[numEntries / 100] << " sec" << endl;
                //     cout << "Average search time: \t" << search[numEntries / 100] << " sec" << endl;
                // }
            }
            generateCSV(insert, search, MAX_ELEMENTS / 100, setName);
            cout << "END OF PROGRAM" << endl;
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
