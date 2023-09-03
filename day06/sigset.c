//信号集演示
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//打印一个字节的8位内容
void printb(char byte){
    for(int i = 0;i < 8;i++){
        printf("%d",byte & 1 << 7 - i ? 1 : 0);
    }
    printf(" ");//空格
}
//打印一块存储区的所有比特位
void printm(void* buf,size_t size){
    for(int i = 0;i < size;i++){
        printb(((char*)buf)[size -1 - i]);
        if((i + 1) % 8 == 0){
            printf("\n");
        }
    }
}
int main(void){
    sigset_t s;//信号集
    printf("填满信号集\n");
    sigfillset(&s);
    printm(&s,sizeof(s));
    printf("清空信号集\n");
    sigemptyset(&s);
    printm(&s,sizeof(s));
    printf("添加2号信号\n");
    sigaddset(&s,SIGINT);
    printm(&s,sizeof(s));
    printf("添加3号信号\n");
    sigaddset(&s,SIGQUIT);
    printm(&s,sizeof(s));
    printf("删除2号信号\n");
    sigdelset(&s,SIGINT);
    printm(&s,sizeof(s));
    printf("信号集中%s2号信号\n",
            sigismember(&s,SIGINT) ? "有" : "无");
    printf("信号集中%s3号信号\n",
            sigismember(&s,SIGQUIT) ? "有" : "无");

    return 0;
}








