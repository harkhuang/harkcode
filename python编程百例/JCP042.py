'''
��Ŀ��ѧϰʹ��auto����������÷�
1.���������������������
2.����Դ���룺
û��auto�ؼ��֣�ʹ�ñ�����������������
'''
num = 2
def autofunc():
    num = 1
    print 'internal block num = %d' % num
    num += 1
for i in range(3):
    print 'The num = %d' % num
    num += 1
    autofunc()
    
