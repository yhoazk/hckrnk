#!/usr/bin/env python3



input_list =['Tokyo', 'London', 'Rome', 'Donlon', 'Kyoto', 'Paris']

# YOUR ALGORITHM



expectedresult = [
    [ 'Tokyo', 'Kyoto' ],
    [ 'London', 'Donlon' ],
    [ 'Rome' ],
    [ 'Paris' ]
]

def solution(lst):
    """
    take the list and apply a hash on each element
    discard elements that do not have the same subset
    It does not have to be a hash, only a count of elements will
    reduce the time
    of the alphabet and thus no rotation will ever give
    the same result
    Now compare only the most probable elements on sub lists
    """
    lcs_lst = []
    for name in lst:
        lcs_lst.append(sorted(name.lower()))
    for e in lcs_lst:
        for w in lcs_lst:
            if e == w:
                pass
    print(lcs_lst)


def naive_solution(lst):
    result = []
    while(True):
        pair = []
        if len(lst) == 0:
            break
        curr_city = lst.pop()
        print("paaaaaaaaapend: " + curr_city)
        pair.append(curr_city)
        for _ in range(len(curr_city)):
            # compare the rotated version of the city name, this has to compare the list len(city name) times
            for city in lst:
                print(curr_city + "*" + city)
                if len(curr_city) != len(city):
                    print("will never be")
                    break
                if curr_city.lower() == city.lower():
                    print(curr_city + "-------------------"+ city)
                    lst.remove(city)
                    pair.append(city)
            print("**********")
            curr_city = curr_city[1:] + curr_city[:1]
        result.append(pair)
    return result


if __name__ == "__main__":
    solution(input_list)
    res=naive_solution(input_list)
    print(":::::::::::::::::::::::")
    print(res)
