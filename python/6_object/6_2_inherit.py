#!/usr/bin/python
#filename:inherit.py

class SchoolMember:
    '''Represents any school member.'''
    def __init__(self,name.age):
        self.name = name
        self.age = age
        print'(Initialized SchoolMember:%s)'%self.name

    def tell(self)
        '''Tell my details'''
        print 'Name:"%s" Age:"%s"'%(self.name,self.age),

class Techer (SchoolMember):
    '''Represent a teacher.'''
    def __init__(self, name, age)
