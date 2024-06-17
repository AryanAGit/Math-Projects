import math
import matplotlib.pyplot as plt
#Instructions on bottom

step = 0.001 #euler step size
center = 0.0 #center of graph
radius = 15 #radius of graph from center
size=(radius*2)/step  #amount of points
intCond = 0.0 #initial condition for center
#differential equation to plot
#must be in the form of y' = f(x, y)
def de(x: float, y: float):
  return (x*math.cos(x*y)-y) 

#variables holding values to graph
xP = [0.0]*int(size/2)
xN = [0.0]*int(size/2)
yP = [0.0]*int(size/2)
yN = [0.0]*int(size/2)

#eulers method, returns the delta y
def euler(x, y):
  return step *de(x, y)


yN[0]=intCond #initial condition
yP[0]=intCond #initial condition

#iterates through each x value
for i in range(int(0.5*size)):
  #add a tiny delta x 
  xN[i] = center - step * i
  xP[i] = center + step * i
  if( i < (int(size/2)-1)):
    #change the y value by delta y
    yP[i+1] = yP[i] + euler(xP[i], yP[i])
    yN[i+1] = yN[i] - euler(xN[i], yN[i])

xN = xN[::-1]
yN = yN[::-1]

#creates a line segment between each consecutive point
plt.plot(xP, yP, color = 'crimson') 
plt.plot(xN, yN, color = 'navy')

plt.title("")
plt.xlabel("X values")
plt.ylabel("f(x) values")

plt.show()




# to use different functions in the DE you can use the following:
# sin() = math.sin()
# cos() = math.cos()
# ln() = math.log()
# e^x = math.exp()
# x^n = x**n
# Python needs you to use both x and y, so if you want to use just x, input something like
# y' = x +y -y
# any DE works as long as it is continuous/defined and the curve doesnt grow without bound 
# too quickly
