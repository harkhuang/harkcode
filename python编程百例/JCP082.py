'''
������82��
��Ŀ���˽���ת��Ϊʮ����
1.�������������������������������
2.����Դ���룺
'''
if __name__ == '__main__':
    n = 0
    p = raw_input('input a octal number:\n')
    for i in range(len(p)):
        n = n * 8 + ord(p[i]) - ord('0')
    print n
