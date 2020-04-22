import matplotlib.pyplot as plt
import pandas as pd


def plotDataSet(structureName, dataSet):
    header_list = ["Iteration", "Insert Time", "Search Time"]
    df = pd.read_csv('./'+structureName+'/Outputs/insert_search_performance_linked_list_' +
                     dataSet+'.csv', sep=',', names=header_list)
    df["Insert Time"] = 1e6 * df["Insert Time"]
    df["Search Time"] = 1e6 * df["Search Time"]

    print(df)

    ax = plt.gca()

    df.plot(kind='line', x='Iteration', y='Insert Time', ax=ax)
    df.plot(kind='line', x='Iteration', y='Search Time', color='red', ax=ax)

    plt.title(structureName.replace('_', ' ')+': Times for '+dataSet)
    plt.ylabel('Time in microseconds')

    plt.savefig('./Graphs/'+structureName+'_'+dataSet+'.png')
    plt.show()

    print("Plot saved in Graphs Folder")


plotDataSet('Linked_List', 'dataSetA')
plotDataSet('Linked_List', 'dataSetB')
