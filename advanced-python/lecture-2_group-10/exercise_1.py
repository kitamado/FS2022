'''
a) Load and Investigate the sound 
'''

from scipy.io.wavfile import read
import matplotlib.pyplot as plt
import numpy as np

# Visualizing the sound wave
fs, sounds = read('./sounds.wav')
plt.plot(sounds)
plt.show()
# plt.savefig('figure.png')

# Playing the signal
import sounddevice as sd
import time
sd.play(sounds, fs)
time.sleep(1)


'''
b) Split the sounds into two
'''
n_sounds = sounds.shape[0]

# The description in doc is wrong, I heard the sound and the first half is door and the second half is frog so I changed the order
sound_door_slam, sound_frog_ribbit = np.split(sounds, [int(n_sounds/2)])


'''
c) Silent Period
numpy array filled with zeros, lengh the same as sound
'''
sound_silence = np.zeros(sound_frog_ribbit.shape[0], dtype=float)


'''
d) Concatenate the Signal
'''
new_sound = np.concatenate([sound_frog_ribbit, sound_silence,
						sound_frog_ribbit, sound_silence, sound_door_slam])

# Plot the soundwave
plt.plot(new_sound) 
plt.show() 

# Play the soundwave
sd.play(new_sound, fs)
time.sleep(2)