file = open("test.txt") 
for line in file.xreadlines():
	if line[0] == 'a':
		print line 

