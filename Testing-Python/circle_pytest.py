import math
import pytest

def area_circle(radius):
    return math.pi*radius*radius

def test_area_circle_00():
   assert area_circle(7.0) == pytest.approx(154.0, rel=1e-3)

def test_area_circle_01():
   assert area_circle(10.0) == pytest.approx(314.16, rel=1e-3)
