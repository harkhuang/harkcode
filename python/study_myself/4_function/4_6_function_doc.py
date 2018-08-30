#!/usr/bin/python

#filename: function_doc.py

def printMax(x,y):
	'''prints the max of two numbers.
	the two values must be integers.'''
	x = int(x)
	y = int(y)
	if x>y:
		print x, 'is maximum'
	else:
		print y, 'is maximum'

printMax(3,5)
print printMax.__doc__
