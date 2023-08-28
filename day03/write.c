//向文件写入数据
#include<stdio.h>
#include<string.h>
#include<unistd.h>// write() close()
#include<fcntl.h>// open()

int main(void){
    //打开文件
    int fd = open("./shared.txt",
                    O_WRONLY|O_CREAT|O_TRUNC,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //向文件写入数据
    char* buf = "hello world!";
    ssize_t size = write(fd,buf,strlen(buf));
    if(size == -1){
        perror("write");
        return -1;
    }
    printf("实际写入%ld个字节\n",size);
    //关闭文件
    close(fd);
    return 0;
}



