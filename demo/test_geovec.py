#!/usr/bin/env python

import unittest
import math

def abs_norm(data):
    
    value = sum([ math.fabs(i) for i in data])
    return value

class geovec_tests(unittest.TestCase):
    """ 
    TestCase provides multiple test assert implementations, see help(unittest.TestCase) for more details. 
    All definitions of unittest.TestCase are registered with the unittest TestRunner by default that will instantiate each derivative and sequentially call all methods found that start with 'test' 
    """
    
    def setUp(self):
        """ called before any function starting with test_ is entered """
        pass

    def tearDown(self):
        """ called after any function starting with test_ is entered """
        pass
    
    def test_module_exists(self):
        try:
            import geovec
        except:
            self.fail("geovec does not exist")

    def test_instance_geovec(self):
        import geovec
        t = geovec.geovec()

    def test_instance_geovec_data(self):
        import geovec
        t = geovec.geovec(42, 43, 44)
        self.assertEqual(t.data,[42,43,44])
            
    def test_instance_mag(self):
        import geovec
        t = geovec.geovec(1, 1, 1, 1)
        mag = t.mag()
        self.assertAlmostEqual(mag,2,5)

    def test_instance_variable_mag(self):
        import geovec
        t = geovec.geovec(1, 1, 1, 1)
        mag = t.mag(abs_norm)
        self.assertAlmostEqual(mag,4,5)
        
        
if __name__=="__main__":
    #instantiate and call geovec_tests
    unittest.main()
