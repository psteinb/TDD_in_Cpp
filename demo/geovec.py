#!/usr/bin/env python

import math

def euc_norm(data):
    value = sum([ i*i for i in data])
    return math.sqrt(value)


class geovec():

    def __init__(self, *args):
        self.data = []
        
        if type(args) != type(self.data):
            for item in args:
                self.data.append(item)
        else:
            self.data.extend(args)
        pass

    def mag(self, func = euc_norm):
    
        value = func(self.data)
        return value
