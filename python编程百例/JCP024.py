'''
������24�� 
��Ŀ����һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡�
1.�����������ץס�������ĸ�ı仯���ɡ� 
2.����Դ���룺
'''
#����һ
a = 2.0
b = 1.0
s = 0
for n in range(1,21):
    s += a / b
    t = a
    a = a + b
    b = t
print s
#������
s = 0.0
for n in range(1,21):
    s += a / b
    b,a = a , a + b
print s

s = 0.0
for n in range(1,21):
    s += a / b
    b,a = a , a + b
print s
#������
l = []
for n in range(1,21):
    b,a = a,a + b
    l.append(a / b)
print reduce(lambda x,y: x + y,l)
