//动态库的动态加载
#include<stdio.h>
#include<dlfcn.h>

int main(void){
    //将动态库载入内存
    void* handle = dlopen("./shared/libmath.so",RTLD_NOW);
    if(handle == NULL){
        fprintf(stderr,"dlopen:%s\n",dlerror());
        return -1;
    }
    //获取库中函数的地址
    double (*add)(double,double) = dlsym(handle,"add");

    //使用函数
    //卸载动态库
    return 0;
}







