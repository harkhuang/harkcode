'''
����99��
��Ŀ:�����������ļ�A��B,�����һ����ĸ,Ҫ����������ļ��е���Ϣ�ϲ�(����ĸ˳������), 
 �����һ�����ļ�C��.
1.�������:
2.����Դ����:
'''
if __name__ == '__main__':
    import string
    fp = open('JCP099.py')
    a = fp.read()
    fp.close()

    fp = open('JCP098.py')
    b = fp.read()
    fp.close()

    fp = open('C.txt','w')
    l = list(a + b)
    l.sort()
    s = ''
    s = s.join(l)
    fp.write(s)
    fp.close()
    
