import pandas as pd
import numpy as np

df = pd.read_csv('./strava_v2.csv')

'''
a) Loop through rows
Using .iloc() method of pandas dataframe
'''
for row_idx in range(25,36):
	row = df.iloc[row_idx]
	elev_gain_per_km = row['total_elevation_gain'] / row['length_km']
	print(f'Run = %dth, Length of run = %.2f, elevation gain = %.2f, gain per km = %.2f'
				% (row_idx, row['length_km'], row['total_elevation_gain'], elev_gain_per_km))

'''
b) Average heart-rate
Using .iloc() method for indexing and built-in dataframe .mean() for calculating mean
'''
avg_heart_rate_range = df.iloc[25:36].average_heartrate.mean()
print('Average heart-rate:', avg_heart_rate_range)

'''
c) Heart-rate and elevation gain
'''
run_highest_elev_gain = df.iloc[25:36].total_elevation_gain.idxmax() 
avg_heartrate_highest_elev_gain = df.iloc[run_highest_elev_gain].average_heartrate
if  avg_heartrate_highest_elev_gain > avg_heart_rate_range:
	print('Heart-rate : %.1f, True' % avg_heartrate_highest_elev_gain)
else:
	print('Heart-rate : %.1f, False' % avg_heartrate_highest_elev_gain)