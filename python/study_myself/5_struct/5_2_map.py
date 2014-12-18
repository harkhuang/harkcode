#!/usr/bin/python
#filename:map.py
#this is dictionary 

#'ab'is short for 'a'adress'b'ook

ab = {'Swaroop':'swaroopch@byteofpython.info',
    'Larry':'larry@wall.org',
    'Matsumoto':'matz@ruby-lang.org',
    'Spammer':'spammer@hotmail.com'}
#Access the value by key
print "Swaroop's address is %s"%ab['Swaroop']

#Adding a key/value pair
ab['Guido'] = 'guido@python.org'
#Deleting a key/value pair
del ab['Spammer']
print '\n There are %d contacts in the address-book\n'%len(ab)

for iname,address in ab.items():
    print 'Contact %s at %s'%(iname,address)
if 'Guido' in ab:#OR ab.has_key('Guido')
    print "\nGuido's address is %s "%ab['Guido']
