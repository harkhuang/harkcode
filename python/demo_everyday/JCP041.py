'''
������41��
��Ŀ��ѧϰstatic���徲̬�������÷�������
1.���������
2.����Դ���룺
'''
# pythonû�����������,ֻ��������:)
def varfunc():
    var = 0
    print 'var = %d' % var
    var += 1
if __name__ == '__main__':
    for i in range(3):
        varfunc()

# attribut of class
# ��Ϊ���һ�����԰�
class Static:
    StaticVar = 5
    def varfunc(self):
        self.StaticVar += 1
        print self.StaticVar

print Static.StaticVar
a = Static()
for i in range(3):
    a.varfunc()
