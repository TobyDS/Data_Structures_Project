import matplotlib.pyplot as plt
import pandas as pd
import subprocess
import os


def runProgram(structureName, dataSet):
    if(structureName == "Linked_List"):
        # print("Compiling driver.cpp")
        subprocess.call(["g++", "-std=c++11", "./Linked_List/ll.cpp",
                         "./Linked_List/driver.cpp", "-o""./Linked_List/driver.out"])  # Compiles program
        print("Linked List: Running driver.out on dataSet"+dataSet)
        # Change directory (this prevents path errors in c++ program)
        os.chdir('./Linked_List/')
        # Execute on dataSet, redirect output so not shown (> /dev/null 2>&1)
        os.system("./driver.out "+dataSet+"> /dev/null 2>&1")
        os.chdir('..')  # Reset directory


def plotDataSet(structureName, dataSetName):
    header_list = ["Iteration", "Insert Time",
                   "Search Time"]  # Assign column headers
    df = pd.read_csv('./'+structureName+'/Outputs/insert_search_performance_linked_list_' +
                     dataSetName+'.csv', sep=',', names=header_list)  # Read file into pandas dataframe
    # Change times from seconds to microseconds for ease of graph reading
    df["Insert Time"] = 1e6 * df["Insert Time"]
    df["Search Time"] = 1e6 * df["Search Time"]

    plt.figure(figsize=(7.2,4.8),dpi=200)
    ax = plt.gca()  # Get current x-axis (allows for multiple plots)
    # Plot both sets of times as line graphs
    df.plot(kind='line', x='Iteration', y='Insert Time', ax=ax)
    df.plot(kind='line', x='Iteration', y='Search Time', color='red', ax=ax)

    plt.title(structureName.replace('_', ' ') +
             ': Times for '+dataSetName, y=1.08,pad=1)
    plt.ylabel('Time in microseconds')

    ax.legend(["Avg insertion times", "Avg search times"], loc='lower center', bbox_to_anchor=(0.5, 1.01), ncol=2,
              borderaxespad=0, frameon=False, prop={'size': 8})
    

    plt.savefig('./Graphs/'+structureName+'_'+dataSetName+'.png')
    plt.show()

    print('Plot '+structureName+'_'+dataSetName+'.png saved in Graphs Folder')


runProgram("Linked_List", "A")
runProgram("Linked_List", "B")
print("-------------------")
plotDataSet('Linked_List', 'dataSetA')
plotDataSet('Linked_List', 'dataSetB')
