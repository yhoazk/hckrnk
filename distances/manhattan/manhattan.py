#!/usr/bin/env python3

import math
import unittest


class distances(unittest.TestCase):

    def getManhattanDistance(self, p1, p2):
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1])

    def runTestCases(self):
        self.assertEqual(self.getManhattanDistance((0,0),(1,1)), 2)
        #self.assertEqual(self.getManhattanDistance((0,3),(4,0)), 8)


if __name__ == '__main__':
    DUT = distances()
    DUT.runTestCases()
