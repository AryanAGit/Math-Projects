#plots the points from the chaos game
import numpy as np
import matplotlib.pyplot as plt
size = 2000  # Image width # Image height
xmax = 1.4
xmin = -0.4
ymax = 1.6
ymin = -0.2
image = np.full((size, size), 255)
Xfix = (xmax-xmin)/size
Yfix = (ymax-ymin)/size
with open('input.txt', 'r') as file:
    for line in file:
     
        words = line.split()
        x = float(words[0])
        y = float(words[1])
        posX = int((x-xmin)/Xfix)

        posY = int((ymax-y)/Yfix)
    

        if(posY<size and posX<size and posY>-1 and posX>-1):
            image[posY, posX] = 0  # Set pixel value to 255 (white)
 
 

# Display the image

plt.figure(figsize=(8, 8))
plt.imshow(image, cmap='grey')
plt.axis('on')
plt.colorbar()  # Add colorbar for reference
plt.show()
print("Done")
