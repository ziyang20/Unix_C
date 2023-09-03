//无名管道
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建无名管道
    printf("%d进程:创建无名管道\n",getpid());
    int fd[2];//用来输出管道的读端和写端描述符
    if(pipe(fd) == -1){
        perror("pipe");
        return -1;
    }
    printf("fd[0] = %d\n",fd[0]);
    printf("fd[1] = %d\n",fd[1]);
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程接收数据
    if(pid == 0){
        printf("%d进程:接收数据\n",getpid());
        printf("%d进程:关闭写端\n",getpid());
        close(fd[1]);
        for(;;){
            char buf[64] = {};
            ssize_t size = read(fd[0],buf,sizeof(buf)-1);
            if(size == -1){
                perror("read");
                return -1;
            }
            if(size == 0){
                printf("%d进程:父进程关写端\n",getpid());
                break;
            }
            printf("%s",buf);
        }
        printf("%d进程:关闭读端\n",getpid());
        close(fd[0]);
        printf("%d进程:大功告成\n",getpid());
        return 0;
    }
    //父进程不停发送数据
    printf("%d进程:发送数据\n",getpid());
    printf("%d进程:关闭读端\n",getpid());
    close(fd[0]);
    for(;;){
        //通过键盘获取要发送的数据
        char buf[64] = {};
        fgets(buf,sizeof(buf),stdin);
        // ! 结束
        if(strcmp(buf,"!\n") == 0){
            break;
        }
        //通过管道写端写入管道
        if(write(fd[1],buf,strlen(buf)) == -1){
            perror("write");
            return -1;
        }
    }
    printf("%d进程:关闭写端\n",getpid());
    close(fd[1]);
    //父进程收尸
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    printf("%d进程:大功告成\n",getpid());
    return 0;
}



