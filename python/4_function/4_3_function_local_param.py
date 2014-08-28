#!/usr/bin/python

#Filename:4_3.py

def func(x):
	print 'x is', x
	x=2
	print 'Changed local x to',x


x=50 #globl x  no space before the param   
func(x)
print 'x is still',x

