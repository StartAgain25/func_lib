# coding:utf-8

import numpy as np
from matplotlib import pyplot as plt
from scipy.fftpack import fft, ifft
import cmath

N = 300
fs = 300

t = np.linspace(0,1,N)
data1 = 1.2*np.cos(2*np.pi*t)
# data2 = 2.1*np.cos(20*np.pi*t)
data2 = 2.1*np.cos(7*np.pi*t)
# data3 = 2.1*np.cos(20*np.pi*t)
data = data1 + data2

sp = np.fft.fft(data)
sp = abs(sp)


A = 2*sp/N
F = np.arange(0,N)

# plt.subplot(411)
plt.plot(F,A)
#设置坐标轴刻度
my_x_ticks = np.arange(0, 5, 0.2)
my_y_ticks = np.arange(1.0, 2.4, 0.2)
plt.xticks(my_x_ticks)
plt.yticks(my_y_ticks)
plt.axis([0,5,1.0,2.4])
# plt.subplot(412)
# plt.plot(t,data1)
# plt.subplot(413)
# plt.plot(t,data2)
# plt.subplot(414)
# plt.plot(t,data3)
plt.show()