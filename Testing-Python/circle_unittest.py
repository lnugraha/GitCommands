import unittest, math
import numpy as np

def circle_area(r):
    if type(r) not in [int, float]:
        raise TypeError("Proper number required")
    elif (r<0):
        raise ValueError("Cannot have negative radius")
    else:
        return math.pi*(r**2)

class CircleCase(unittest.TestCase):
    def test_area(self):
        self.assertAlmostEqual(circle_area(1), math.pi)
        self.assertAlmostEqual(circle_area(0), 0.0)
        self.assertAlmostEqual(circle_area(2.1), math.pi*2.1*2.1)

    def test_values(self):
        self.assertRaises(ValueError, circle_area, -2)

    def test_types(self):
        self.assertRaises(TypeError, circle_area, 3-2j)
        self.assertRaises(TypeError, circle_area, True)
        self.assertRaises(TypeError, circle_area, False)

if __name__ == '__main__':
    unittest.main()
