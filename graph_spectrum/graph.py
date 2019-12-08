import matplotlib.pyplot as plt
import numpy as np

cold = open("coldside.txt","r")
hot = open("hotside.txt","r")

I = []
I2 = []
Energy = []

i = 0


for line in cold :
    line = line.split()
    a = line[0]
    if i == 0:
        b = line[5]
    else :
        b = line[6]
    I.append(float(a))
    Energy.append(float(b))
    i += 1

for line in hot :
    line = line.split()
    a = line[0]
    I2.append(float(a))



plt.plot(Energy,I)
plt.plot(Energy, I2)
