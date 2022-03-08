''' 
a) Load bitmap and change colors
'''

import matplotlib.pyplot as plt
import numpy as np

im = plt.imread('./python.bmp')
im = np.array(im)
block_shape = [10,10]
im[50:60,10:20,] = np.array([[[255,0,0]]*10]*10, dtype='uint8') #Red Patch
plt.imshow(im)
plt.show()
# plt.savefig('figure.png')


'''
b) Flipping
'''
im_top_half, _ = np.split(im, [int(im.shape[0]/2)], axis=0) #Top half along X axis
im_top_half_flipped = np.flip(im_top_half, axis=1)
plt.imshow(im_top_half_flipped)
plt.show()
# plt.savefig('figure.png')


'''
c) Splicing
'''
_, im_bottom_half = np.split(im, [int(im.shape[0]/2)], axis=0)
im_splice = np.concatenate([im_top_half_flipped, im_bottom_half], axis=0)
plt.imshow(im_splice)
plt.show()
# plt.savefig('figure.png')

# Also plot your original image and check whether it has changed.
plt.imshow(im)
plt.show()

'''
d) Shallow Copy
'''
im_split = np.split(im, [int(im.shape[0]/2)], axis=0)
im_top_half_view = im_split[0].view()

# replace all [0,0,0] to [255,0,0]
# numpy array slicing returns view so im_top_half_view[:,:,:].base is still im
im_top_half_view[:,:,:] = np.where(im_top_half_view == [0,0,0], [255,0,0], im_top_half_view)

# Plot Base
plt.imshow(im_top_half_view.base)
plt.show()
# plt.savefig('figure.png')

# Plot Original Image
plt.imshow(im)
plt.show()
# plt.savefig('figure1.png')


'''
e) Copies and pointers
The original image in 2c did not change because 'split' function returns a deep copy, whereas
using the "view" in 2d, it gives a shallow copy and hence any change made to the view
will also reflect in the base i.e. the original image
'''
