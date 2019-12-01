import math
from fuel_calc import fuel_calc

# expected: 3295206
if __name__ == "__main__":
    acc = 0
    with open("input.log") as data:
        for line in data:
            acc += fuel_calc(int(line))
    print("ans: {}".format(acc))