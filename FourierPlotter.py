import matplotlib.pyplot as plt
import math
a0 = 0.0
c = 0.0
rangePlot = 5
numPts = 10000
aInit = False
aList = []
bList = []
color1 = (0, 72/255, 85/255)
color2 = (255/255, 215/255, 0/255)

with open("C:/code/fourierSeries/fourier.txt", "r") as f1:
    lines = f1.readlines()
    for line in lines:
        line = line.strip()
        words = line.split("\t")
        if aInit == False:
            print(line)
            a0 = float(words[0])
            c = float(words[1])
            aInit = True
        else:
            aList.append(float(words[0]))
            bList.append(float(words[1]))

f1.close()

def F(x):
    f = a0
    for i in range(len(aList)):
        index = i+1
        f += (aList[i])*math.cos(x*index*3.14159265/c)
        f += (bList[i])*math.sin(x*index*3.14159265/c)
    return f


def f(x):
    try:
        return (x*(x-1)*(x+1))
    except Exception as e:
        return 0



x = [0.0]*10000
y = [0.0]*10000
z = [0.0]*10000

for i in range(10000):
    x[i] = -rangePlot + 2*rangePlot*i/10000
    y[i] = F(x[i])
    z[i] = f(x[i])


plt.plot(x, y, color = color1)
plt.plot(x, z, color = color2)
# Add a title and labels
plt.title("Fourier Series")
plt.xlabel("x")
plt.ylabel("y")

# Show the plot
plt.show()