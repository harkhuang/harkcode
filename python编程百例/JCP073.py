'''
��Ŀ���������һ������������
1.���������
2.����Դ���룺
'''
if __name__ == '__main__':
    ptr = []
    for i in range(5):
        num = int(raw_input('please input a number:\n'))
        ptr.append(num)
    print ptr
    ptr.reverse()
    print ptr
