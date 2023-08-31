//孤儿进程
#include<stdio.h>
#include<unistd.h>
int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码
    if(pid == 0){
        printf("%d进程:我的父进程是%d\n",
                getpid(),getppid());
        sleep(2);
        printf("%d进程:我的父进程是%d\n",
                getpid(),getppid());

        return 0;
    }
    //父进程代码
    sleep(1);
    printf("%d进程:我是父进程,拜拜\n",getpid());
    return 0;
}
