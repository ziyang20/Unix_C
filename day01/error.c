//错误处理
#include<stdio.h>
#include<string.h>// strerror()
#include<stdlib.h>// malloc()
#include<errno.h>// int errno
// errno --> 0 --> 12 
int main(void){
    int* p = malloc(0xffffffffffffffff);
    /*if(p == NULL){
        //mallco失败
        //获取失败原因-->编号-->errno
        printf("errno = %d\n",errno);
        printf("malloc: %s\n",strerror(errno));
        perror("malloc");
        return -1;
    }*/
    free(p);
    p = NULL;
    //调用fopen函数
    FILE* fp = fopen("./test.c","r");
    //if(errno){
    if(fp == NULL){
        perror("fopen");
        return -1;
    }
    fclose(fp);
    return 0;
}
