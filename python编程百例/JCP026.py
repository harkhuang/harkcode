'''
������26�� 
��Ŀ�����õݹ鷽����5!��
1.����������ݹ鹫ʽ��fn=fn_1*4!
2.����Դ���룺
'''
def fact(j):
    sum = 0
    if j == 0:
        sum = 1
    else:
        sum = j * fact(j - 1)
    return sum

for i in range(5):
    print '%d! = %d' % (i,fact(i))
