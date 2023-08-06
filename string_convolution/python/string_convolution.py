#!/usr/bin/env python3


def convolution_naive(k, q):
    max_tgt = len(k) + len(q) - 2
    pairs = []
    res = ''
    for tgt in range(max_tgt + 1):
        kn = 0; qn = 0
        while True:
            if tgt == (kn + qn) and (kn < len(k) and qn < len(q)):
                pairs.append((kn, qn))
                res += k[kn]+q[qn]
            qn += 1
            if qn > tgt:
                qn = 0
                kn += 1
            if kn > tgt:
                break
    # print(pairs)
    return res

def test(k,q,exp, fnc_version):
    conv = fnc_version(k,q)
    if conv == exp:
        print("PASS")
    else:
        print(f"Not pass:\nObt: {conv}\nExp: {exp}")

if __name__ == "__main__":
    test("+-", "12345",'+1+2-1+3-2+4-3+5-4-5', convolution_naive)
    test("123", "ABC",'1A1B2A1C2B3A2C3B3C', convolution_naive)
    test("Hello", "World",'HWHoeWHreolWHlerlolWHdellrlooWedlllrooldllorldolod', convolution_naive)
    test("", "Empty",'', convolution_naive)
    test("split", " ",'s p l i t ', convolution_naive)