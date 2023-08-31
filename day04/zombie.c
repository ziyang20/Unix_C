//僵尸进程演示
#include<stdio.h>
#include<unistd.h>

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码,快点死
    if(pid == 0){
        printf("%d进程:我是子进程,马上死\n",getpid());
        return 0;
    }
    //父进程代码,忙
    printf("%d进程:我是父进程,忙着呢\n",getpid());
    sleep(15);
    return 0;
}




