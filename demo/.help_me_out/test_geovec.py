#!/usr/bin/env python

import unittest

def abs_sum(data):
    value = sum(data)
    return value

class geovec_tests(unittest.TestCase):

    """ class to test  """
    def setUp(self):
        self.random_numbers = [1.2, 4.2, 5.7, 18]
        self.all_ones = 4*[1]
        return

    def tearDown(self):
        return
    
    def test_module_exists(self):
        try:
            import geovec
        except:
            self.fail("geovec does not exist")
            
    def test_geovec_default_ctor(self):
        try:
            import geovec
            t = geovec.geovec()
        except:
            self.fail("geovec cannot be constructed")
    
    def test_geovec_ctor_w_args(self):
        try:
            import geovec
            t = geovec.geovec(self.all_ones)
        except:
            self.fail("geovec cannot be constructed with "+str(self.all_ones))


    def test_geovec_ctor_fills(self):
        import geovec
        t = geovec.geovec(self.all_ones)
        self.assertEqual(len(t.data), len(self.all_ones))


    def test_geovec_ctor_fills_any(self):
        import geovec
        t = geovec.geovec(self.all_ones,1)
        self.assertEqual(len(t.data), len(self.all_ones)+1)
        self.assertEqual(t.data,5*[1])

    def test_geovec_mag(self):
        import geovec
        t = geovec.geovec(self.all_ones)
        mag = t.mag()
        self.assertAlmostEqual(mag, 2, 5)

    def test_geovec_mag_abs(self):
        import geovec
        t = geovec.geovec(self.all_ones)
        mag = t.mag(abs_sum)
        self.assertAlmostEqual(mag,4,5)

if __name__=="__main__":
    unittest.main()
