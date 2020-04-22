import matplotlib.pyplot as plt
import pandas as pd

header_list = ["Iterations", "Insert Time", "SearchTime"]
df = pd.read_csv('./Linked_List/Outputs/insert_search_performance_linked_list_dataSetA.csv',sep=',',names=header_list)

print(df)
