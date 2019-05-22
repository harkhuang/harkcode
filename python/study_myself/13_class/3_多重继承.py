#!/usr/bin/python

class Cat():
    def Cattalk(self):
        print('%s: miaomiaomiao~~~' % self.name)
 
 
class Dog():
    def Dogtalk(self):
        print('%s: wangwangwang~~~' % self.name)
 

class Animal(Cat,Dog):
    def __init__(self, name):
        self.name = name
        self.infos = ["student","20","chinese"]
    def talk(self):
        print "i am ",self.name ,'xasasfafafkkfasjklaf~~~~'
    def animal_talk(ojbk):   
        ojbk.talk()
 
p = Animal("monster")

p.talk()
p.Cattalk()
p.Dogtalk()