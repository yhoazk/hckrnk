#!/usr/bin/env python3

import math
import unittest


class distances(unittest.TestCase):

    def getEuclideanDistance(self, p1, p2):
        return math.sqrt(math.pow((p1[0]-p2[0]),2) + math.pow((p1[1]-p2[1]),2))

    def runTestCases(self):
        self.assertEqual(self.getEuclideanDistance((0,3),(4,0)), 5)
        self.assertEqual(self.getEuclideanDistance((0,3),(4,0)), 8)


if __name__ == '__main__':
    DUT = distances()
    DUT.runTestCases()
