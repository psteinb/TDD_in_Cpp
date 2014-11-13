#!/usr/bin/env python
import math 

def euc_mag(data):
    value = sum([i*i for i in data])
    return math.sqrt(value)

class geovec():

    def __init__(self, *args):
        
        self.data = [ ]
        for item in args:
            if type(item) == type(self.data):
               self.data.extend(item)
            else:
               self.data.append(item)
            
        pass

    def mag(self, func = euc_mag):

        value = func(self.data)
        return value
