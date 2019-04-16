#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_COUNT 1000*1000

void fun(int i)

{

         char* ptr = (char*)malloc(i);
         free(ptr);
}



void* fun_thread()

{

         int i = 0;
         int j = 1;

         while(i++<MAX_COUNT)

         {

                   j ++;
                   fun(j);
                   if ( j>1024 )
                            j = 1;

         }

}
#define MSECOND 1000000

int main()

{
         struct timeval tpstart,tpend;
         float timeuse;
         gettimeofday(&tpstart,NULL);
         pthread_t _deliver_t;
         pthread_create(&_deliver_t, NULL, fun_thread, NULL);

         int i = 0;

         int j = 1;

         while(i++<MAX_COUNT)

         {

                   j ++;

                   fun(i);

                   if ( j > 1024 )

                            j = 1;

                   //usleep(1);

         }

        

         gettimeofday(&tpend,NULL);



         timeuse=MSECOND*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;

         timeuse/=MSECOND;

         printf("Used Time:%f\n", timeuse);



         return 0;

}
