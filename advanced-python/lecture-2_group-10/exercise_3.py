'''
a) Amplify the signal
'''
from scipy.io.wavfile import read
import matplotlib.pyplot as plt
import numpy as np

# Visualizing the sound wave
fs, sounds = read('./sounds.wav')
sounds_amplified = np.multiply(sounds, 2)


'''
b) Sub-exercise title
'''
temperatures = np.load('./temperatures.npy', allow_pickle=True)
temp_max_each_city = np.max(temperatures, axis=1) 
print("Maximum temperature for each city:", temp_max_each_city)
avg_temp_each_day = np.mean(temperatures, axis=0)
print("\nAverage temperature across the five cities for each day: ", avg_temp_each_day)

'''
c) Maximum Temperature
'''
max_temp_all = np.max(temperatures) # By default flattened output is used
# We use np.unravel_index to get 2D coordinate from flattened array index
index_max_temp_all = np.unravel_index(np.argmax(temperatures, axis=None), temperatures.shape)
print("\n",index_max_temp_all)