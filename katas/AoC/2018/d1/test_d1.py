
import pytest
from chronal_calib import *

def test_ShouldReturn3WhenListOf3():
    assert 3 == chronal_calibration([+1.+1,+1])


def test_ShouldReturn0():
    assert 0 == chronal_calibration([+1.+1,-2])


def test_ShouldReturn6():
    assert -6 == chronal_calibration([-1.-2,-3])
