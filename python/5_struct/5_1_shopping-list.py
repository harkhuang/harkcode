#!/usr/bin/python
#filename:list.py
#this is shopping list

shoplist = ['apple','mango','carrot','banana']
print'i have',len(shoplist),'items to purchase.'

print 'These item are:',#Notice the comma at end of the line
for itemsss in shoplist:
    print '\n'
    print itemsss

print '\nI also have buy rise'
shoplist.append('rise')
print'My shopping list is now',shoplist


print '\n'
print'I will sort my list now'
shoplist.sort()
print 'Sorted shopping list is',shoplist

print '\n'
print 'Sorted shopping list is',shoplist[0]
olditem = shoplist[0]
del shoplist[0]
print'I bought the',olditem
print 'My shopping list is now',shoplist
