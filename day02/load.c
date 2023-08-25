//动态库的动态加载
#include<stdio.h>
#include<dlfcn.h>

int main(void){
    //将动态库载入内存
    void* handle = dlopen("../day01/shared/libmath.so",
                            RTLD_NOW);
    if(handle == NULL){
        fprintf(stderr,"dlopen:%s\n",dlerror());
        return -1;
    }
    //获取库中函数的地址
    double (*add)(double,double) = dlsym(handle,"add");
    if(add == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    double (*sub)(double,double) = dlsym(handle,"sub");
    if(sub == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    void (*show)(double,char,double,double)
                = dlsym(handle,"show");
    if(show == NULL){
        fprintf(stderr,"dlsym:%s\n",dlerror());
        return -1;
    }
    //使用函数
    double a = 123,b = 456;
    show(a,'+',b,add(a,b));
    show(a,'-',b,sub(a,b));
    //卸载动态库
    dlclose(handle);
    return 0;
}







