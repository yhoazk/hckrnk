import math

def fuel_calc(fuel):
    f = int(math.floor(fuel / 3.0) - 2) 
    return f if f >= 0 else 0