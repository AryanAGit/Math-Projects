#computes DFT of a given function



import matplotlib.pyplot as plt
import math
import numpy as np
import cmath
import random
samples = 160

frequency = 16#hz sampling
color1 = (0, 72/255, 85/255)
t = [0.0]*samples
x = [0.0]*samples
X = [0.0]*int((samples/2))
m = [0.0]*int((samples/2))
F = [0.0]*int((samples/2))
def f(x):
    #return math.sin(2*x*math.pi)
  # return 1.273240*math.sin(3.141593* x)  +0.424413*math.sin( 9.424778* x)  +0.254648*math.  sin( 15.707963* x)  +0.181891 *math. sin( 21.991149* x)  +0.141471 *math. sin( 28.274334* x)
   #return 3*math.sin(3.141593 * x) + 2*math.sin( 9.424778* x) +random.uniform(-0.5, 0.5) +0.5*math.  sin( 15.707963* x)
   if (x-2)*(x-2) <1:
       return 1
   else:
      return 0
   """if x == 0:
       return 1
   else: 
       return  math.sin(x)/x
   """
   # math.exp(-x**2)
    # return math.cos(x)
   #return 3*math.sin(2*x*math.pi)+ math.sin(4*x*math.pi) +4* math.sin(x*math.pi)+2* math.sin(12*x*math.pi)
  #return math.cos(2*x*math.pi)

for i in range(samples):
    t[i] = i/frequency
    x[i] = f(t[i])
    
    
for i in range(int(samples/2)):
  F[i] = frequency*i/samples
  c =complex(0, 0)
  for n in range(samples):
    c+= x[n]*cmath.exp(-2j * math.pi*i*n/samples)

  X[i]=c
  m[i] = 2*abs(X[i])/samples


fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 8))  # Adjust the figsize as needed
x_ticks = np.arange(0, frequency/2, 0.5)  # Starting from 0 to 10 with a step of 0.5
ax1.set_xticks(x_ticks)
ax1.set_xlabel('Frequency (Hz)')
ax1.set_ylabel('Magnitude')
ax1.bar(F, m, width = 0.2, color = color1)
# Add a title and labels
ax1.set_title("DFT")

x_ticks2 = np.arange(0, samples/frequency, 0.5)  # Starting from 0 to 10 with a step of 0.5
ax2.set_xticks(x_ticks2)
ax2.set_xlabel('Time (s)')
ax2.set_ylabel('Magnitude')
ax2.plot(t, x, color = color1)
# Add a title and labels
ax2.set_title("Time-Amplitude")
plt.tight_layout()
plt.show()



