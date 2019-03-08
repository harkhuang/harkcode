#!/usr/bin/python

#####def Person():

class Person:
    def set_name(self, name):
        self.name = name
    def get_name(self):
        return self.name
    def greet(self):
        print "hell everyon...i am {}".format(self.name)

foo = Person()
bar = Person()
foo.set_name('hark huang')
bar.set_name('alex mahon')
foo.greet()
bar.greet()