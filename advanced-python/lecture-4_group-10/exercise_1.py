import pandas as pd
import numpy as np

df = pd.read_csv('./strava.csv')

'''
a) Create Column 
'''
df['average_speed_kmph'] = df['average_speed_mph'] * 1.60934

'''
b) Length of Each run 
Arithmetic using Columns : distance (m) / 1000
'''
df['length_km'] = df['moving_time_h'] * df['average_speed_kmph']

'''
c) Saving : exporting dataframe
'''
df.to_csv('./strava_v2.csv')

'''
d) Count number of entries fulfilling a condition
Using filters on columns 
'''
long_runs = df[df['length_km']>5]
print(f'Number of Runs with distance > 5km : %d' % len(long_runs))

short_runs = df[df['length_km']<=5]
print(f'Number of Runs with distance <= 5km : %d' % len(short_runs))

'''
e) Find Averages 
'''
mean_heart_rate_long = long_runs['average_heartrate'].mean()
print(f'Mean Heart Rate for Long Runs : %.2f' % mean_heart_rate_long)

mean_heart_rate_short = short_runs['average_heartrate'].mean()
print(f'Mean Heart Rate for Short Runs : %.2f' % mean_heart_rate_short)