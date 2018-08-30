import time
print 'time.time():'
print time.time()

print '\n'
print 'time.ctime(22):'
print time.ctime(2)

print '\n'
print 'time.localtime():'
print time.localtime()

print '\n'
print 'time.gmtime():'
print time.gmtime()


print '\n'
print "time.strftime('%Y-%m-%d',time.localtime(time.time()))"
print time.strftime('%Y-%m-%d',time.localtime(time.time()))

print '\n'
print 'mktime'
print time.mktime(time.localtime())

print '\n'
print 'time.sleep(seconds)'
print 'time.sleep(1)'






print time.localtime(132106899602)