'''
������98��
��Ŀ���Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ��Ȼ�������һ�������ļ���test���б��档
������������ַ����ԣ������� 
1.���������
2.����Դ���룺
'''
if __name__ == '__main__':
    fp = open('test.txt','w')
    string = raw_input('please input a string:\n')
    string = string.upper()
    fp.write(string)
    fp = open('test.txt','r')
    print fp.read()
    fp.close()
