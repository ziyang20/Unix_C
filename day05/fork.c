//验证子进程是否会继承父进程的信号处理方式
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //对2号信号进行忽略处理
    if(signal(SIGINT,SIG_IGN) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //对3号信号进行捕获处理
    if(signal(SIGQUIT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码
    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        for(;;);//暂时不结束
        return 0;
    }
    //父进程收尸
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    return 0;
}




