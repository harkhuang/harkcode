'''
������38��
��Ŀ����һ��3*3����Խ���Ԫ��֮�� 
1.�������������˫��forѭ�����������ά���飬�ٽ�a[i][i]�ۼӺ������
2.����Դ���룺
'''
if __name__ == '__main__':
    a = []
    sum = 0.0
    for i in range(3):
        a.append([])
        for j in range(3):
            a[i].append(float(raw_input("input num:\n")))
    for i in range(3):
        sum += a[i][i]
    print sum
    
