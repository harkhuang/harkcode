'''
������85��
��Ŀ���ж�һ�������ܱ�����9����
1.���������
2.����Դ���룺
'''
if __name__ == '__main__':
    zi = int(raw_input('input a number:\n'))
    n1 = 1
    c9 = 1
    m9 = 9
    sum = 9
    while n1 != 0:
        if sum % zi == 0:
            n1 = 0
        else:
            m9 *= 10
            sum += m9
            c9 += 1
    print '%d can be divided by %d 9' % (sum,c9)
