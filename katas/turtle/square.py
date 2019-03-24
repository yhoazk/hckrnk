# -*- coding: utf-8 -*-
"""
Created on Tue Mar 19 23:51:16 2019

@author: porko
"""

from turtle import Turtle

def draw_eck(turtle, size, eck=3):
    assert(eck >= 3)
    for i in range(0, eck):
        turtle.forward(size)
        turtle.left(360/eck)
        
        
turtle = Turtle()
for ecks in range(3,14):
    draw_eck(turtle, 100, ecks)
