
import turtle
import matplotlib.pyplot as plt
from scipy import signal
import numpy as np
import os

class dly_system:
    flt_size = None
    dly = None
    wind = None
    sys_state = None
    def __init__(self, _flt_size=20, _dly=5):
        self.dly = np.zeros(_dly) # transport delay
        self.flt_size = _flt_size
        self.wind = signal.hann(self.flt_size) # system delay
        self.sys_state = np.zeros(self.flt_size)
    
    
    def step(self, ctrl):
        self.dly = np.roll(self.dly, 1)
        self.dly[0] = ctrl
        self.sys_state = np.roll(self.sys_state, 1)
        self.sys_state[0] = self.dly[-1]
        
        return sum(signal.convolve(self.sys_state, self.wind)) / float(self.flt_size)
        
        

if "__main__" == __name__:
    system = dly_system()
    x = np.zeros(100)
    x[25:75] = 1
    y = []
    for v in x:
        c = system.step(v)
        print(c)
        y.append(c)
        
    fg, (sig, out) = plt.subplots(2,1)
    sig.plot(x)
    out.plot(y)
    fg.show()
    os.system("pause")