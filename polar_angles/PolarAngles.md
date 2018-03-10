# Polar Angles

A point *(x,y)* in the cartesian plane, makes an angle theta with the positive
direction of the x-axis. Theta varies in the interval *[0,2PI]* radians, i.e.
greather than or equal to zero but less than 2PI radians.

For example, the polar angle of the point *(1,2)* as marked in the image
is 63.4 degrees (multiply by PI/180).

![]()


## The task

Given a list of points in the 2D plane, sort them in ascending order of
their polar angle. In case multiple points shre exactly the same angle,
the one with lesser distance from the origin (0,0) should occur earlier
in the sorted list.

## Input format
The first line contains an interger N
Followed by N lines containing pairs of space separated integers x and y
which represent the coordinates of the points in the cartesian plane.

## Constraints

1<= N <= 1000
-100 <= x,y <= 100

The point (0,0) will not be present in the list of points

## Output format
The output should contain N lines. Each line should cointain two
integers x,y correspondig to a point in the original lis. Display
the points in ascending order of their polar angle.

Sample input and expected output are given.


---
In this excercise the main problem was the stability of the sort operation and also
how to correctly apply two sorting orders at the same time. 
