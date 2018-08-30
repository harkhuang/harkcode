import fnmatch 
import os

for filename in os.listdir('.'):
    if fnmatch.fnmatch(filename , '?.txt'):
        print 'Text file'
