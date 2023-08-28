//文件读写位置
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
// 1 hello world! 2 hello world!linux!
// 3 hello linux! 4 hello linux!world!

int main(void){
    //打开文件,得到文件描述符
    int fd = open("./lseek.txt",
                    O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //向文件中写入数据  hello world!
    char* buf = "hello world!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //修改文件读写位置
    if(lseek(fd,-6,SEEK_END) == -1){
        perror("lseek");
        return -1;
    }
    //再次向文件写入数据 linux!
    buf = "linux!";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //再次修改文件读写位置
    if(lseek(fd,8,SEEK_END) == -1){
        perror("lseek");
        return -1;
    }
    //第三次写入数据
    buf = "<-- this is a hole";
    if(write(fd,buf,strlen(buf)) == -1){
        perror("write");
        return -1;
    }
    //关闭文件
    close(fd);
    return 0;
}



