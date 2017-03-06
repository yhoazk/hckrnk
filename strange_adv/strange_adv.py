#!/usr/bin/python

import math
users_like = 0
n = 0 # days
i = 0 # curr_day
def calc_users_like_adv(users):
    global n
    global i
    global users_like
    if i <= n:
        i += 1
        k = math.floor(users/2)
        users_like += k
        calc_users_like_adv(k)
    else:
        return
