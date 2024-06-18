#uses zipped data file for graphing to workaround file size limit
import numpy as np
import matplotlib.pyplot as plt
import zipfile
import time

xmax = 1
xmin = -2.0
ymax = 1.5
ymin = -1.5
size = 6000 #px count of width and height
count = 0
image = np.full((size, size), 500)
Xfix = (xmax-xmin)/size
yFix = (ymax-ymin)/size
start = time.time()
with zipfile.ZipFile("output1.zip", 'r') as zip_file1:
     with zip_file1.open("output1.txt") as file1:
         for line in file1:
             words = line.split()
             x = float(words[0])
             y = float(words[1])
             color = 0
             if len(words) > 2:
                 color = int(words[2])

             posX = int((x-xmin)/Xfix)
             posY = int((ymax-y)/yFix)
             count += 1
             if count % 1000000 == 0:
                 print(count)
             if color == 0:
                 color =500
             if(posY<size and posX<size and posX>-1 and posY>-1):
                 image[posY, posX] = color  
file1.close()
zip_file1.close()


with zipfile.ZipFile("output2.zip", 'r') as zip_file2:
     with zip_file2.open("output2.txt") as file2:
         for line in file2:
             words = line.split()
             x = float(words[0])
             y = float(words[1])
             color = 0
             if len(words) > 2:
                 color = int(words[2])

             posX = int((x-xmin)/Xfix)
             posY = int((ymax-y)/yFix)
             count += 1
             if count % 1000000 == 0:
                 print(count)
             if color == 0:
                 color =500
             if(posY<size and posX<size and posX>-1 and posY>-1):
                 image[posY, posX] = color  
zip_file2.close()
file2.close()



with zipfile.ZipFile("output3.zip", 'r') as zip_file3:
     with zip_file3.open("output3.txt") as file3:
         for line in file3:
             words = line.split()
             x = float(words[0])
             y = float(words[1])
             color = 0
             if len(words) > 2:
                 color = int(words[2])

             posX = int((x-xmin)/Xfix)
             posY = int((ymax-y)/yFix)
             count += 1
             if count % 1000000 == 0:
                 print(count)
             if color == 0 :
                 color =500
             if(posY<size and posX<size and posX>-1 and posY>-1):
                 image[posY, posX] = color  
file3.close()
zip_file3.close()


with zipfile.ZipFile("output4.zip", 'r') as zip_file4:
     with zip_file4.open("output4.txt") as file4:
         for line in file4:
             words = line.split()
             x = float(words[0])
             y = float(words[1])
             color = 0
             if len(words) > 2:
                 color = int(words[2])

             posX = int((x-xmin)/Xfix)
             posY = int((ymax-y)/yFix)
             count += 1
             if count % 1000000 == 0:
                 print(count)
             if color == 0:
                 color = 500
             if(posY<size and posX<size and posX>-1 and posY>-1):
                 image[posY, posX] = color  
file4.close()
zip_file4.close()



plt.figure(figsize=(8, 8))
plt.axis('off')

end = time.time()
duration = end - start

#top correct = 500px = 0.25*size/(xmax-xmin)
#right correct = 5500 px
#bottom correct = 5500 px

print(duration)
print(count/(end-start)) #lines per second processed

plt.imshow(image, cmap='nipy_spectral_r')
plt.colorbar() 
plt.show()
    
