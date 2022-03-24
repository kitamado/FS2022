import pandas as pd
import numpy as np

df = pd.read_csv('./strava.csv')

'''
a) Create list from column values
Using build in constructor of Series object, using the index values provided
'''
l_rows = list(sorted(df.iloc[:5].moving_time_h))
l_rows_keys = ['Shortest', 'Short', 'Medium', 'Long', 'Longest']
l_series = pd.Series(data = l_rows, index = l_rows_keys) 
print(l_series)

'''
b) Read Value
Using dictionary like key-value access method of Series
'''
l_medium = l_series['Medium']
print('\nMoving time with key "Medium" = %s \n' % l_medium)

'''
c) Dictionaries
'''
l_dict = dict(zip(l_rows_keys, l_rows))
l_dict_series = pd.Series(l_dict)
print(l_dict_series)

'''
d) Index
Using index argument to filter 'Shortest' and 'Longest' keys
'''
l_dict = dict(zip(l_rows_keys, l_rows))
l_dict_series = pd.Series(l_dict, index=['Shortest','Longest'])
print(l_dict_series)