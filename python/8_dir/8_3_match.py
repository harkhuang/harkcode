import fnmatch
import os

for filename in os.listdir('.'):
    if fnmatch.fnmatch(filename,'*.txt'):
        print open(filename).read()
    elif fnmatch.fnmatch(filename,'*.exe'):
        print filename
