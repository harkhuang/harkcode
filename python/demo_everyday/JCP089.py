'''
������89��
��Ŀ��ĳ����˾���ù��õ绰�������ݣ���������λ���������ڴ��ݹ������Ǽ��ܵģ����ܹ������£�
������ÿλ���ֶ�����5,Ȼ���úͳ���10��������������֣��ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������
1.���������
2.����Դ���룺
'''
from sys import stdout
if __name__ == '__main__':
    a = int(raw_input('input a number:\n'))
    aa = []
    aa.append(a % 10)
    aa.append(a % 100 / 10)
    aa.append(a % 1000 / 100)
    aa.append(a / 1000)

    for i in range(4):
        aa[i] += 5
        aa[i] %= 10
    for i in range(2):
        aa[i],aa[3 - i] = aa[3 - i],aa[i]
    for i in range(3,-1,-1):
        stdout.write(aa[i])
