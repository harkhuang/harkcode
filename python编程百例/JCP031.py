'''
����31��
��Ŀ�����������ڼ��ĵ�һ����ĸ���ж�һ�������ڼ��������һ����ĸһ���������
�������жϵڶ�����ĸ��
1.�����������������ȽϺã������һ����ĸһ�������ж����������if����жϵڶ�����ĸ��
2.����Դ���룺
'''
from sys import stdin
letter = stdin.read(1)
stdin.flush()
while letter  != 'Y':
    if letter == 'S':
        print 'please input second letter'
        letter = stdin.read(1)
        stdin.flush()
        if letter == 'a':
            print 'Saturday'
        elif letter  == 'u':
            print 'Sunday'
        else:
            print 'data error'
            break
    elif letter == 'F':
        print 'Friday'
        break
    elif letter == 'M':
        print 'Monday'
        #break
    elif letter == 'T':
        print 'please input second letter'
        letter = stdin.read(1)
        stdin.flush()
        if letter  == 'u':
            print 'Tuesday'
        elif letter  == 'h':
            print 'Thursday'
        else:
            print 'data error'
            break
    elif letter == 'W':
        print 'Wednesday'
    else:
        print 'data error'
    letter = stdin.read(1)
    stdin.flush()
        
