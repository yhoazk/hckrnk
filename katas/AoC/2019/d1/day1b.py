from fuel_calc import fuel_calc

# calculate the fuel needed to take the fuel

def fuel2fuel(mass):
    if mass == 0:
        return 0
    else:
        m = fuel_calc(mass)
        # print("mass fuel: {}".format(m))
        return m + fuel2fuel(m)

def non_rec_fuel2fuel(mass):
    tot = 0
    mass = (mass // 3) - 2 # only mass of fuel
    while mass > 0:
        tot += mass
        mass = (mass // 3) - 2
    return tot

if __name__ == "__main__":
    # print(fuel2fuel(100756)) # = 50346
    print(non_rec_fuel2fuel(100756)) # = 50346
    acc = 0
    acc2  =0
    with open("input.log") as data:
        for line in data:
            acc += fuel2fuel(int(line))
            acc2 += non_rec_fuel2fuel(int(line))
    print("ans:  {}".format(acc)) # ans: 4939939
    print("ans2: {}".format(acc2)) # ans: 4939939