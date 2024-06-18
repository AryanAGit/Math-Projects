
import math
import matplotlib.pyplot as plt
size=628
#function to graph
def f(x):
  return (2**x)#math.sin(x)
def dx(x):
  return (f(x+0.001)-f(x))/0.001

def Ndx(x, n):
  if(n == 1):
    return dx(x)
  else:
     return (Ndx(x+0.001, n-1)-Ndx(x, n-1))/0.001

def integral(x):
  area = 0
  n = 10000
  width = x /n
  for i in range(n):
    j = i+1
    trapezoid = width * 0.5 * (f(i*width)+ f(j*width))
    area += trapezoid
  return area
def tangentLine(x):
  m = dx(x)
  x1 = [-(size/200), size/200]
  y1 = [m*(x1[0]-x) + f(x), m*(x1[1]-x) + f(x)]
  plt.plot(x1, y1, color = 'brown')

x = [0.0]*size
y = [0.0]*size
z= [0.0]*size
w =[0.0]*size
v = [0.0]*size
u =[0.0]*size
t = [0.0]*size
for i in range(size):
  x[i] = 0.01 *(i+1) -0.01*size/2
  y[i] = f(x[i])
  z[i]= dx(x[i])
  w[i]= Ndx(x[i], 2)
  v[i]=Ndx(x[i], 3)
  u[i]=Ndx(x[i], 4)
  t[i] = integral(x[i])




plt.plot(x, y, color = 'red') #f(x)
plt.plot(x, z, color = 'blue') # f'(x)
plt.plot(x, w, color = 'purple') #f''(x)
plt.plot(x, v, color = 'green') #f"'(x)
plt.plot(x, u, color = 'yellow') #f^(4) (x)
plt.plot(x, t, color = 'aqua') # F(x)
tangentLine(-2)  # tan line at x = c



plt.title("Basic Plot")
plt.xlabel("X values")
plt.ylabel("f(x) values")

plt.show()
