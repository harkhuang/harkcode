'''
������43��
��Ŀ��ѧϰʹ��static����һ�÷���������
1.���������
2.����Դ���룺
��һ��static�������÷���python��û�У���ʾһ��python������ʹ�÷���
'''
class Num:
    nNum = 1
    def inc(self):
        self.nNum += 1
        print 'nNum = %d' % self.nNum

if __name__ == '__main__':
    nNum = 2
    inst = Num()
    for i in range(3):
        nNum += 1
        print 'The num = %d' % nNum
        inst.inc()
