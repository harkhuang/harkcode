'''
������66��
��Ŀ������3����a,b,c������С˳�������������
1.�������������ָ�뷽����
2.����Դ���룺
'''
if __name__ == '__main__':
    n1 = int(raw_input('n1 = :\n'))
    n2 = int(raw_input('n2 = :\n'))
    n3 = int(raw_input('n3 = :\n'))

    def swap(p1,p2):
        return p2,p1

    if n1 > n2 : n1,n2 = swap(n1,n2)
    if n1 > n3 : n1,n3 = swap(n1,n3)
    if n2 > n3 : n2,n3 = swap(n2,n3)

    print n1,n2,n3
