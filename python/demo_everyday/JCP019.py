'''
������19��
��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6=1��2��3.���
�������ҳ�1000���ڵ�����������
1. �������������ճ���<--��ҳ����14. 
2.����Դ���룺
'''
from sys import stdout
for j in range(2,1001):
    k = []
    n = -1
    s = j
    for i in range(1,j):
            if j % i == 0:
                n += 1
                s -= i
                k.append(i)
    
    if s == 0:
        print j
        for i in range(n):
            stdout.write(k[i])
            stdout.write(' ')
        print k[n]
            
