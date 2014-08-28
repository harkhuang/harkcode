#include<stdio.h>

float buf2float(char *buf)
{
    char buf_t[4];
    float f_res;

    buf_t[0] = *(buf+3);
    buf_t[1] = *(buf+2);
    buf_t[2] = *(buf+1);
    buf_t[3] = *(buf+0);
    f_res = *(float*)(buf_t);
    
    return f_res;
}


int main()
{
	
	char buf[4];
	float fres;
	buf[0]='12';
	buf[1]='12';
	buf[2]='12';
	buf[3]='12';
	
	fres = *(float*)(buf);
	printf("%f \n",fres);
}