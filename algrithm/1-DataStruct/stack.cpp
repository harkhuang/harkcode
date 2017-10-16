/*************************************************************************
	> File Name: stack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月12日 星期四 10时45分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAX 20


typedef struct  _Element
{    
    int size;  
    char *p;
}*pElement;

#define ElemType pElement

//  define pointer use ptr  easly 
#define S (*pStack)

using namespace std;


typedef struct SqStack{
    
    // 数组表示一个栈最大的存储空间
    ElemType elem[MAX];


    int top;//记录栈中元素的个数

}Stack,*pStack;



int 
main()
{
        struct SqStack *q;
        int i,y,cord;ElemType a;
        void OutStack(struct SqStack S);
        void InitStack(struct SqStack *p);
        void Push(struct SqStack *p,ElemType x);
        ElemType Pop(struct SqStack *p);
        ElemType GetTop(struct SqStack *p);
        do{
            printf("\n");
            printf("\n           main menu        \n");
            printf("\n     1     InitStack ->OutStack   \n");
            printf("\n     2     push   \n");
            printf("\n     3     pop    \n");
            printf("\n     4     GetTop      \n");
            printf("\n     5     exit    \n");
            printf("\n--------------------------------\n");
            printf("please input your choise( 1, 2, 3, 4, 5)");
            scanf("%d",&cord);
            switch(cord)
            {
                case 1:
                {
                    q=(struct SqStack*)malloc(sizeof(struct SqStack));
                    InitStack(q);
                    OutStack(q);
                }break;
                case 2:
                {
                    printf("please input a=");
                    scanf("%d",&a);
                    Push(q,a);
                    OutStack(q);
                }break;
                case 3:
                {
                    Pop(q);
                    OutStack(q);
                }break;
                case 4:
                {
                    y=GetTop(q);
                    printf("\ny=%d\n",y);
                    OutStack(q);
                }break;
                case 5:
                exit(0);
            }
        }while (cord<=5);
}





//初始化栈
void InitStack(Stack *pStack){

    if(pStack == NULL){
        printf("error\n");
    }
    S.top = 0;
}


//往栈怼入一个元素x
void Push(Stack *pStack,ElemType x){

    if(S.top < MAX-1){
        S.top = S.top+1;
        S.elem[S.top] = x;
    }
}

//
ElemType Pop(Stack *pStack ){
    ElemType tmp;
    if(pStack->top != 0){
        // 保存元素到返回值，这里如果元素不是一个值的话，返回可能需要申请空间
        tmp = pStack->elem[pStack->top];
        pStack->top = pStack->top - 1;
        return tmp;
    }
    else{
        printf("Underflow\n");
        return 0;
    }
}

ElemType GetTop(Stack *pStack){
    ElemType x;
    if(S.top != 0){
        x = S.elem[S.top];
        return (x);
    }
    else{
        printf("Underflow\n");
        return (0);
    }

}

//遍历输出
void OutStack(Stack *pStack){
    int i,j;
    if(S.top == 0){
        printf("the stack is null");
    }
    for(i=S.top;i>0;i--){
        printf("%2d %6d\n",i,S.elem[i]);
    }

}
