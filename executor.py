import matplotlib.pyplot as plt
import pandas as pd
import subprocess
import os
import platform
import sys

print("=== Identified system type: "+platform.system()+" ===")


def runProgram(structureName, dataSet):
    if platform.system() != "Windows":
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
        elif(structureName == "Binary_Search_Tree"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Binary_Search_Tree/bst.cpp",
                             "./Binary_Search_Tree/driver.cpp", "-o""./Binary_Search_Tree/driver.out"])  # Compiles program
            print("Binary Search Tree: Running driver.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('./Binary_Search_Tree/')
            # Execute on dataSet, redirect output so not shown (> /dev/null 2>&1)
            os.system("./driver.out "+dataSet+"> /dev/null 2>&1")
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Linear_Probing"):
            # print("Compiling driverLinear.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverLinear.cpp", "-o""./Hash/driverLinear.out"])  # Compiles program
            print("Hash Table: Running driverLinear.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('./Hash/')
            # Execute on dataSet, redirect output so not shown (> /dev/null 2>&1)
            os.system("./driverLinear.out "+dataSet+"> /dev/null 2>&1")
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Quadratic_Probing"):
            # print("Compiling driverQuadratic.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverQuadratic.cpp", "-o""./Hash/driverQuadratic.out"])  # Compiles program
            print("Hash Table: Running driverQuadratic.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('./Hash/')
            # Execute on dataSet, redirect output so not shown (> /dev/null 2>&1)
            os.system("./driverQuadratic.out "+dataSet+"> /dev/null 2>&1")
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Chaining"):
            # print("Compiling driverChain.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverChain.cpp", "-o""./Hash/driverChain.out"])  # Compiles program
            print("Hash Table: Running driverChain.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('./Hash/')
            # Execute on dataSet, redirect output so not shown (> /dev/null 2>&1)
            os.system("./driverChain.out "+dataSet+"> /dev/null 2>&1")
            os.chdir('..')  # Reset directory
    else:
        if(structureName == "Linked_List"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Linked_List/ll.cpp",
                             "./Linked_List/driver.cpp", "-o""./Linked_List/driver.out"])  # Compiles program
            print("Linked List: Running driver.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('Linked_List')
            # Execute on dataSet, redirect output so not shown
            FNULL = open(os.devnull, 'w')
            subprocess.call(["./driver.out", dataSet],
                            stdout=FNULL,  stderr=subprocess.STDOUT)
            os.chdir('..')  # Reset directory
        elif(structureName == "Binary_Search_Tree"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Binary_Search_Tree/bst.cpp",
                             "./Binary_Search_Tree/driver.cpp", "-o""./Binary_Search_Tree/driver.out"])  # Compiles program
            print("Binary Search Tree: Running driver.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('Binary_Search_Tree')
            # Execute on dataSet, redirect output so not shown
            FNULL = open(os.devnull, 'w')
            subprocess.call(["./driver.out", dataSet],
                            stdout=FNULL,  stderr=subprocess.STDOUT)
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Linear_Probing"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverLinear.cpp", "-o""./hash/driverLinear.out"])  # Compiles program
            print("Hash Table: Running driverLinear.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('Hash')
            # Execute on dataSet, redirect output so not shown
            FNULL = open(os.devnull, 'w')
            subprocess.call(["./driverLinear.out", dataSet],
                            stdout=FNULL,  stderr=subprocess.STDOUT)
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Quadratic_Probing"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverQuadratic.cpp", "-o""./hash/driverQuadratic.out"])  # Compiles program
            print("Hash Table: Running driverQuadratic.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('Hash')
            # Execute on dataSet, redirect output so not shown
            FNULL = open(os.devnull, 'w')
            subprocess.call(["./driverQuadratic.out", dataSet],
                            stdout=FNULL,  stderr=subprocess.STDOUT)
            os.chdir('..')  # Reset directory
        elif(structureName == "Hash_Table_Chaining"):
            # print("Compiling driver.cpp")
            subprocess.call(["g++", "-std=c++11", "./Hash/hash.cpp",
                             "./Hash/driverChain.cpp", "-o""./hash/driverChain.out"])  # Compiles program
            print("Hash Table: Running driverChain.out on dataSet"+dataSet)
            # Change directory (this prevents path errors in c++ program)
            os.chdir('Hash')
            # Execute on dataSet, redirect output so not shown
            FNULL = open(os.devnull, 'w')
            subprocess.call(["./driverChain.out", dataSet],
                            stdout=FNULL,  stderr=subprocess.STDOUT)
            os.chdir('..')  # Reset directory


def plotDataSet(structureName, dataSetName, show):
    header_list = ["Iteration", "Insert Time",
                   "Search Time"]  # Assign column headers
    if(structureName == "Linked_List"):
        df = pd.read_csv('./'+structureName+'/Outputs/insert_search_performance_linked_list_' +
                         dataSetName+'.csv', sep=',', names=header_list)  # Read file into pandas dataframe
    elif(structureName == "Binary_Search_Tree"):
        df = pd.read_csv('./'+structureName+'/Outputs/insert_search_performance_binary_search_tree_' +
                         dataSetName+'.csv', sep=',', names=header_list)
    elif(structureName == "Hash_Table_Linear_Probing"):
        df = pd.read_csv('./Hash/Outputs/insert_search_performance_hash_table_linear_' +
                         dataSetName+'.csv', sep=',', names=header_list)
    elif(structureName == "Hash_Table_Quadratic_Probing"):
        df = pd.read_csv('./Hash/Outputs/insert_search_performance_hash_table_quadratic_' +
                         dataSetName+'.csv', sep=',', names=header_list)
    elif(structureName == "Hash_Table_Chaining"):
        df = pd.read_csv('./Hash/Outputs/insert_search_performance_hash_table_chain_' +
                         dataSetName+'.csv', sep=',', names=header_list)
    # Change times from seconds to microseconds for ease of graph reading
    df["Insert Time"] = 1e6 * df["Insert Time"]
    df["Search Time"] = 1e6 * df["Search Time"]

    plt.figure(figsize=(7.2, 4.8), dpi=200)
    ax = plt.gca()  # Get current x-axis (allows for multiple plots)
    # Plot both sets of times as line graphs
    df.plot(kind='line', x='Iteration', y='Insert Time', ax=ax)
    df.plot(kind='line', x='Iteration', y='Search Time', color='red', ax=ax)

    plt.title(structureName.replace('_', ' ') +
              ': Times for '+dataSetName, y=1.08, pad=1)
    plt.ylabel('Time in microseconds')

    ax.legend(["Avg insertion times", "Avg search times"], loc='lower center', bbox_to_anchor=(0.5, 1.01), ncol=2,
              borderaxespad=0, frameon=False, prop={'size': 8})

    plt.savefig('./Graphs/'+structureName+'_'+dataSetName+'.png')
    if show:
        plt.show()

    print('Plot '+structureName+'_'+dataSetName+'.png saved in Graphs Folder')


show = True if len(sys.argv) > 1 and sys.argv[1] == "-s" else False

runProgram("Linked_List", "A")
runProgram("Linked_List", "B")
runProgram("Binary_Search_Tree", "A")
runProgram("Binary_Search_Tree", "B")
runProgram("Hash_Table_Linear_Probing", "A")
runProgram("Hash_Table_Linear_Probing", "B")
runProgram("Hash_Table_Quadratic_Probing", "A")
runProgram("Hash_Table_Quadratic_Probing", "B")
runProgram("Hash_Table_Chaining", "A")
runProgram("Hash_Table_Chaining", "B")
print("-------------------")
plotDataSet('Linked_List', 'dataSetA', show)
plotDataSet('Linked_List', 'dataSetB', show)
plotDataSet('Binary_Search_Tree', 'dataSetA', show)
plotDataSet('Binary_Search_Tree', 'dataSetB', show)
plotDataSet("Hash_Table_Linear_Probing", "dataSetA", show)
plotDataSet("Hash_Table_Linear_Probing", "dataSetB", show)
plotDataSet("Hash_Table_Quadratic_Probing", "dataSetA", show)
plotDataSet("Hash_Table_Quadratic_Probing", "dataSetB", show)
plotDataSet("Hash_Table_Chaining", "dataSetA", show)
plotDataSet("Hash_Table_Chaining", "dataSetB", show)
