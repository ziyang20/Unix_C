//kill函数演示
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程捕获2号信号
    if(pid == 0){
        printf("%d进程:我是子进程\n",getpid());
        /*if(signal(SIGINT,sigfun) == SIG_ERR){
            perror("signal");
            return -1;
        }*/
        for(;;);//保证子进程不结束
        return 0;
    }
    
    //父进程给子进程发送2号信号
    printf("%d进程:发送2号信号给子进程\n",getpid());
    getchar();//控制执行节奏
    if(kill(pid,SIGINT) == -1){
        perror("kill");
        return -1;
    }
    //判断子进程存在否
    if(kill(pid,0) == 0){
        printf("%d进程:子进程存在\n",getpid());
    }else{//kill失败
        if(errno == ESRCH){
            printf("%d进程:子进程不存在\n",getpid());
        }else{
            perror("kill");
            return -1;
        }
    }
    //收尸
    if(wait(NULL) == -1){
        perror("wait");
        return -1;
    }
    //判断子进程存在否
    if(kill(pid,0) == 0){
        printf("%d进程:子进程存在\n",getpid());
    }else{//kill失败
        if(errno == ESRCH){
            printf("%d进程:子进程不存在\n",getpid());
        }else{
            perror("kill");
            return -1;
        }
    }
    return 0;
}






