//brk函数演示
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("当前堆尾:%p\n",sbrk(0));
    int* p1 = sbrk(0);
    printf("p1 = %p\n",p1);
    brk(p1 + 1);
    *p1 = 123;

    double* p2 = sbrk(0);
    printf("p2 = %p\n",p2);
    brk(p2 + 1);
    *p2 = 3.45;
    
    printf("%d %lg\n",*p1,*p2);

    brk(p1);

    printf("当前堆尾:%p\n",sbrk(0));
    return 0;
}
