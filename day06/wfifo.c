//向管道文件中写入数据
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(void){
    //创建管道文件
    printf("%d进程:创建管道文件\n",getpid());
    if(mkfifo("./fifo",0664) == -1){
        perror("mkfifo");
        return -1;
    }
    //打开管道文件
    printf("%d进程:打开管道文件\n",getpid());
    int fd = open("./fifo",O_WRONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //发送数据
    printf("%d进程:发送数据\n",getpid());
    for(;;){
        //通过键盘获取数据 scanf getchar  fgets read
        char buf[64] = {};
        fgets(buf,sizeof(buf),stdin);
        //人为指定条件,输入!则结束循环 hahah!
        if(strcmp(buf,"!\n") == 0){
            break;
        }
        //写入管道文件
        if(write(fd,buf,strlen(buf)) == -1){
            perror("write");
            return -1;
        }
    }
    //关闭管道文件
    printf("%d进程:关闭管道文件\n",getpid());
    close(fd);
    //删除管道文件
    printf("%d进程:删除管道文件\n",getpid());
    unlink("./fifo");
    printf("%d进程:大功告成\n",getpid());
    return 0;
}







