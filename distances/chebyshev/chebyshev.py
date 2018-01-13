#!/usr/bin/env python3

import math
import unittest


class distances(unittest.TestCase):

    def getChebyshevDistance(self, p1, p2):
        return max(abs(p1[0]-p2[0]), + abs(p1[1]-p2[1]))

    def runTestCases(self):
        self.assertEqual(self.getChebyshevDistance((0,0),(1,0)), 1)
        self.assertEqual(self.getChebyshevDistance((0,0),(1,1)), 1)
        self.assertTrue(self.getChebyshevDistance((0,0),(1,5)) != 1)

if __name__ == '__main__':
    DUT = distances()
    DUT.runTestCases()
