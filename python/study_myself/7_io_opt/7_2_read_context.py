my_file = open('abc.txt')
try:
    all_the_text = my_file.read()
    print all_the_text
    print my_file
finally:
    my_file.close()
    
