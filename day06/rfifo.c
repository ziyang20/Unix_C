//读取管道文件
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void){
    //打开管道文件
    printf("%d进程:打开管道文件\n",getpid());
    int fd = open("./fifo",O_RDONLY);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //接收数据
    for(;;){
        //从管道文件中读取数据
        char buf[64] = {};
        ssize_t size = read(fd,buf,sizeof(buf)-1);
        if(size == -1){
            perror("read");
            return -1;
        }
        if(size == 0){
            printf("%d进程:对方关闭管道文件\n",getpid());
            break;
        }
        //显示
        printf("%s",buf);
    }
    //关闭管道文件
    printf("%d进程:关闭管道文件\n",getpid());
    close(fd);
    printf("%d进程:大功告成\n",getpid());
    return 0;
}






