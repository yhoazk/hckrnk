
import functools

def chronal_calibration(changes):
    return functools.reduce(lambda x,y: x+y, changes, 0)

        
