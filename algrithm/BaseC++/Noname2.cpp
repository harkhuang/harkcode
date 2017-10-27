#include <iostream>  
using namespace std;   
#include<string.h>  
#include <stdio.h>
void* Memcpy(void* dest, void* src,size_t count)  
{  
    int* ret = (int*)dest;  
    const int* pSrc = (const int*)src;  
    while(count--)  
        *ret++ = *pSrc++;  
          
    return ret;  
} 

 
void* Memmove(void* dest, const void* src, size_t count)  
{  
    int* ret = (int*)dest;  
    const int* pSrc = (const int*)src;  
    if(ret<= pSrc || ret >= (pSrc+ count))  
    {  
        while(count--)  
            *ret++ = *pSrc++;  
    }  
    else      
    {  
  
        ret += count -1;  
        pSrc  += count -1 ;  
        while(count--)  
            *ret-- = *pSrc--;  
    }  
    return dest;  
}  
 

int main(int argc, int** argv) {  
  
	char a[10] = "123456789";
	 
	Memcpy(&a[4],a,sizeof(char)*5);  
	  
	printf("%s\n",a);

	char a1[10] = "123456789";
	Memmove(&a1[4],a1,sizeof(char)*5);  

	printf("%s\n",a1);

	char a2[10] = "123456789";
	memmove(&a2[4],a2,sizeof(char)*4);

	printf("%s\n",a2);
	char a3[10] = "123456789";
	memcpy(&a3[4],a3,sizeof(char)*4);
	
	printf("%s\n",a3);
    return 0;  
}  