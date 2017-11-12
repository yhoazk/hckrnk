#!/usr/bin/python
#import time
#from datetime import date

def main():
    currDate = map(int, raw_input().split())
    expDate = map(int, raw_input().split())
    #fmtCurrDate = datetime.date(currDate[2], currDate[1], currDate[0])
    #fmtExpDate = datetime.date(currDate[2], currDate[1], currDate[0])

    fine = 0
    days = 0
    #check for the same year
    if currDate[2] <= expDate[2]:
        #check for the same month
        if currDate[1] <= expDate[1]:
            #check for the same day
            if currDate[0] <= expDate[0]:
                pass # exact day or before
            elif currDate[0] > expDate[0]:
                # delivered within the same mont
                fine = 15 * (currDate[0] - expDate[0])
        elif currDate[1] > expDate[1]:
            fine = 500 * (currDate[1] - expDate[1])
    elif currDate[2] > expDate[2]:
        fine = 10000

    print fine
if __name__ == '__main__':
    main()
