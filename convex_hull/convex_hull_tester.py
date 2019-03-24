#!/usr/bin/env python3

import random
from matplotlib import pyplot as plt
import subprocess
import math

class convex_hull:
    """
    Remember that for a shape to be convex
    a line going through should cut the shape only once
    """
    def __init__(self, _x=10, _y=10):
        self.range_x = _x
        self.range_y = _y
        self.sample_ptsx = []
        self.sample_ptsy = []
        self.jarvis_seed = None
        self.create_points()

    def create_points(self, no_pts=10):
        """
        Generator of points for the convex hull
        """
        for _ in range(no_pts):
            self.sample_ptsx.append( random.randint(0, self.range_x) )
            self.sample_ptsy.append( random.randint(0, self.range_x) )

    def show_pts(self):
        plt.scatter(self.sample_ptsx, self.sample_ptsy, facecolors='blue',alpha=.55, s=100 )
        if self.jarvis_seed is not None:
            plt.scatter(self.jarvis_seed[0], self.jarvis_seed[1], color='yellow')
        # show the seed of the jarvis march
        plt.show()

    def jarvis_march(self):
        """
        - First select the leftmost point
        - Then iterate through all points and select the one with the greatest
          interior angle
        """
        min_idx = self.sample_ptsx.index(min(self.sample_ptsx))
        leftmost_pt = (self.sample_ptsx[min_idx], self.sample_ptsy[min_idx])
        self.jarvis_seed = leftmost_pt

        curr_min_val, curr_min_indx = 100, 100
        for n, pt in enumerate(zip(self.sample_ptsx, self.sample_ptsy)):
            ang = math.atan2(self.jarvis_seed[0] - pt[0], self.jarvis_seed[1] - pt[1])
            if ang < curr_min_val:
                curr_min_val = ang
                curr_min_indx = n

        print("Idx {} x: {} y: {}".format(curr_min_indx, self.sample_ptsx[curr_min_indx], self.sample_ptsy[curr_min_indx]))

    def chans(self):
        pass
    
    def graham(self):
        """
        This is a mix of the pass two algorithms
        which basically creates a wrap of wraps
        and then sends the result to the jarvis march
        """
        pass
    

if '__main__' == __name__:
    ch = convex_hull()
    ch.jarvis_march()
    ch.show_pts()