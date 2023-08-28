//访问测试
#include<stdio.h>
#include<unistd.h>

int main(int argc,char* argv[]){
    // ./a.out hello.txt
    // 文件hello.txt不存在
    // 文件hello.txt可读,可写,不可执行
    if(access(argv[1],F_OK) == -1){
        printf("文件%s不存在\n",argv[1]);
    }else{
        //存在
        printf("文件%s",argv[1]);
        if(access(argv[1],R_OK) == -1){
            printf("不可读,");
        }else{
            printf("可读,");
        }

        if(access(argv[1],W_OK) == -1){
            printf("不可写,");
        }else{
            printf("可写,");
        }

        if(access(argv[1],X_OK) == -1){
            printf("不可执行\n");
        }else{
            printf("可执行\n");
        }
    }

    return 0;
}
