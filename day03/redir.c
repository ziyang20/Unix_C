//输出重定向
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    //关闭文件描述符1,使之空闲
    close(/*1*/STDOUT_FILENO);
    //打开文件out.txt
    int fd=open("./out.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    printf("fd = %d\n",fd);
    return 0;
}
