'''
������9��
��Ŀ��Ҫ����������������̡�
1.�����������i�����У�j�������У�����i+j�ĺ͵ı仯����������ڷ��񣬻��ǰ׷���
2.����Դ���룺
#include "stdio.h"
main()
{
int i,j;
for(i=0;i<8;i++)
��{
����for(j=0;j<8;j++)
������if((i+j)%2==0)
��������printf("%c%c",219,219);
������else
��������printf(" ");
������printf("\n");
��}
}
'''
import sys
for i in range(8):
    for j in range(8):
        if(i + j) % 2 == 0:
            sys.stdout.write(chr(219))
            sys.stdout.write(chr(219))
        else:
            sys.stdout.write(' ')
    print ''
