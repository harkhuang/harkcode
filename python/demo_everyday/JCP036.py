'''
������36��
��Ŀ����100֮�ڵ�����������
1.���������
2.����Դ���룺 
'''
from math import sqrt
if __name__ == '__main__':
    N = 100
    a = range(0,N)
    for i in range(2,int(sqrt(N))):
        for j in range(i + 1,N):
            if (a[i] != 0) and (a[j] != 0):
                if a[j] % a[i] == 0:
                    a[j] = 0
    print
    for i in range(2,N):
        if a[i] != 0:
            print "%5d" % a[i]
            if (i - 2) % 10 == 0:
                print
