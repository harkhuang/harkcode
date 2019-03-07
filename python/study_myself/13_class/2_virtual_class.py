#!/usr/bin/python

class Animal(object):
    def __init__(self, name):
        self.name = name
    def talk(self):
        print(self.name,'ao~~~~')
    def animal_talk(ojbk):
        ojbk.talk()
 
class Cat(Animal):
    def talk(self):
        print('%s: miaomiaomiao~~~' % self.name)
 
 
class Dog(Animal):
    def talk(self):
        print('%s: wangwangwang~~~' % self.name)
 
 
a = Dog('a')
Animal.animal_talk(a) 
 