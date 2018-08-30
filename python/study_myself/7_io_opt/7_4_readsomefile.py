file1 = open('abc.txt')
try:
    while True:
        chunk = file1.read(100)
        if not chunk:
            break
        #do_somethin_with(chunk)
finally:
    file1.close()
