//获取环境变量
#include<stdio.h>

int main(int argc,char* argv[],char* envp[]){
    //environ 记录数组首元素的地址
    extern char** environ;
    /*for(char** pp = environ;*pp;pp++){
        printf("%s\n",*pp);
    }*/

    for(char** pp = envp;*pp;pp++){
        printf("%s\n",*pp);
    }
    printf("environ = %p\n",environ);
    printf("envp    = %p\n",envp);

    return 0;
}
