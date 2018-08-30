fileread = open('abc.txt')
try:
    all_the_text = fileread.read()
    print all_the_text
finally:
    fileread.close
#write string
output1 = open('data','w')

#write binary
output1 = open('data','wb')

#write append
output1 = open('data','w+')

file1 = open('thefile.txt','w')
file1.write(all_the_text)
file1.close()


file2 = open('thefile.txt','r')
try:
    all_the_text = file2.read()
    print all_the_text
finally:
    file2.close()
