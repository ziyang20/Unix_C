//段错误演示
#include<stdio.h>

int main(void){
    //int* p = (int*)0x12345678;
    //*p = 10;//p->虚拟地址->物理地址->物理内存
    //const int i = 1;//栈区
    static const int i = 1;// 代码区Q
    //i = 2;
    // i -> const int
    // &i -> const int*
    *(int*)&i = 2;
    printf("i = %d\n",i);
    return 0;
}
