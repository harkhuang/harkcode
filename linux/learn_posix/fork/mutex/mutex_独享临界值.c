#include <stdio.h>
#include <pthread.h>




pthread_mutex_t  mutex_value;
int a = 1;
void * fun()
{

//������Դ�Ľӿ�
//�����Դû�б�ռ��  ֱ��������
//�����Դ��ռ��      �����ڴ�
pthread_mutex_lock(&mutex_value);//wait after a use off it  and release it 

printf("end lock in pthrad.\n");
a = 999;
pthread_exit((void *)"hello ,thread.\n");
}

int main()
{
pthread_t tid;
void *p = NULL;
pthread_mutex_init(&mutex_value, NULL);
printf("befor lock in main poress\n");
pthread_mutex_lock(&mutex_value);//only myown can use it 
printf("after lock in main poress\n");
pthread_create(&tid, NULL, fun, NULL);
//pthread_mutex_unlock(&mutex_value);
printf("%d\n",a);

sleep(1);
printf("%d\n",a);

//printf("pthread return value is : %s ", (char*) p);

return 0;
}