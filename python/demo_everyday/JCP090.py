'''
������90��
��Ŀ��ר����һ�⣬�������
1.���������
2.����Դ���룺
'''
if __name__ == '__main__':
    M = 5
    a = [1,2,3,4,5]
    i = 0
    j = M - 1
    while i < M:
        a[i],a[j] = a[j],a[i]
        print a
        i += 1
        j -= 1
    for i in range(5):
        print a[i]
