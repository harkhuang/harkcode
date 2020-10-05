
using namespace std;


// 此处的p是一个临时拷贝的副本,变量用完就没有了
// 一个指针的副本而已
void getMemory(int *&p)
{
    p = (int *)malloc(sizeof(int));
    printf("指针p的值  p:%p\n", p);
    printf("指针p指向地址的值  *p:%p\n", *p);
    printf("指针p指向地址的值  *p:%d\n", *p);
    printf("指针p的地址  &p:%p\n", &p);
}

void test()
{
    // 针对指针的测试
    
    int a =99999;
    int *p;
    p = &a;
    printf("1.变量a值  a:%p\n", a);
    printf("1.变量a值  a:%d\n", a);
    printf("2.变量a的地址   &a:%p\n", &a);
    printf("3.指针p的值  p:%p\n", p);
    printf("4.指针p指向地址的值  *p:%p\n", *p);
    printf("4.指针p指向地址的值  *p:%d\n", *p);
    printf("5.指针p的地址  &p:%p\n", &p);
    

    printf("----------------------------\n");
    // 二级指针的定义

    int *myp = &a;
    printf("指针myp的值  myp:%p\n", myp);
    printf("指针myp指向地址的值  *myp:%p\n", *myp);
    printf("指针myp指向地址的值  *myp:%d\n", *myp);
    printf("指针myp的地址  &myp:%p\n", &myp);
    getMemory(myp);

    int **p2;
    p2 = &p;
    printf("指针p2的值  p2:%p\n", myp);
    printf("指针p2指向地址的值  *p2:%p\n", *myp);
    printf("指针p2指向地址的值  *p2:%d\n", *myp);
    printf("指针p2的地址  &p2:%p\n", &myp);

    getchar();
    getchar();
}
