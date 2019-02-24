# -*- coding: utf-8 -*-
"""
Spyder Editor

Dies ist eine temporäre Skriptdatei.
"""

permute =  "qwert"

lehmer_code = "30110"


def get_comb(l, code):
    l = list(l)
    code = [ print(l.pop(int(x)), end='') for x in list(code)]
    print('')


get_comb(permute, lehmer_code)