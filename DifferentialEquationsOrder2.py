import math
import matplotlib.pyplot as plt
#Instructions on bottom

step = 0.0001 #euler step size
center = 0.0 #center of graph
radius = 3.142 #radius of graph from center
size=(radius*2)/step  #amount of points
intCond = 0.0 #initial condition for center
intSlope = 1.0 #initial condition for slope

#differential equation to plot (y'' = f(x, y, y'))
def de(x: float, y: float, u: float):
  return (y-math.sin(x)-y-u+u) 

#returns delta y'
def euler(x, y, u):
  return step *de(x, y, u)

#variables holding values to graph
#let u = y'
xP = [0.0]*int(size/2)
xN = [0.0]*int(size/2)
yP = [0.0]*int(size/2)
yN = [0.0]*int(size/2)
uN = [0.0]*int(size/2)
uP = [0.0]*int(size/2)

yN[0]=intCond #initial condition
yP[0]=intCond #initial condition
uN[0]=intSlope #initial condition
uP[0]=intSlope #initial condition

#iterates through each x value
for i in range(int(0.5*size)):
  #add a tiny delta x 
  xN[i] = center - step * i
  xP[i] = center + step * i
  if( i < (int(size/2)-1)):
    #change the y' value by delta y'
    uP[i+1] = uP[i] + euler(xP[i], yP[i], uP[i])
    uN[i+1] = uN[i] - euler(xN[i], yN[i], uN[i])
    #change y value using slope of previous pt
    yP[i+1] = yP[i] + step*uP[i]
    yN[i+1] = yN[i] - step*uN[i]
    
xN = xN[::-1]
uN = uN[::-1]
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
#DE is in form y'' = f(x, y, y')
# any DE works as long as it is continuous/defined and the curve doesnt grow without bound 
# too quickly
