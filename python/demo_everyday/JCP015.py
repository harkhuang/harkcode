'''
������15��
��Ŀ�����������������Ƕ������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��
������60�����µ���C��ʾ��
1.���������(a>b)?a:b��������������Ļ������ӡ�
2.����Դ���룺
��֧����������
'''
score = int(raw_input('input score:\n'))
if score >= 90:
    grade = 'A'
elif score >= 60:
    grade = 'B'
else:
    grade = 'C'

print '%d belongs to %s' % (score,grade)
