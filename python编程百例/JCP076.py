'''
������76��
��Ŀ����дһ������������nΪż��ʱ�����ú�����1/2+1/4+...+1/n,������nΪ����ʱ�����ú���
������1/1+1/3+...+1/n(����ָ�뺯��)
1.���������
2.����Դ���룺
'''
def peven(n):
    i = 0
    s = 0.0
    for i in range(2,n + 1,2):
        s += 1.0 / i
    return s

def podd(n):
    s = 0.0
    for i in range(1, n + 1,2):
        s += 1 / i
    return s

def dcall(fp,n):
    s = fp(n)
    return s

if __name__ == '__main__':
    n = int(raw_input('input a number:\n'))
    if n % 2 == 0:
        sum = dcall(peven,n)
    else:
        sum = dcall(podd,n)
    print sum
