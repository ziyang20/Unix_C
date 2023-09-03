//信号屏蔽
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//信号处理函数
void sigfun(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
}
//假装更新数据库
void updatedb(void){
    for(int i = 0;i < 5;i++){
        printf("正在更新第%d条数据....\n",i+1);
        sleep(1);
    }
}
int main(void){
    int signum = /*SIGINT*/ 50;
    //对2号信号进行捕获处理
    if(signal(signum,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("%d进程:对%d号信号进行屏蔽\n",getpid(),signum);
    sigset_t set;//信号集
    sigemptyset(&set);//清空信号集
    sigaddset(&set,signum);//添加2号信号
    sigset_t old;//用来输出以前的信号掩码
    if(sigprocmask(SIG_SETMASK,&set,&old) == -1){
        perror("sigprocmask");
        return -1;
    }
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程向父进程发送2号信号
    if(pid == 0){
        for(int i = 0;i < 5;i++){
            printf("%d进程:向父进程发送%d号信号\n",
                    getpid(),signum);
            if(kill(getppid(),signum) == -1){
                perror("kill");
                return -1;
            }
        }
        return 0;
    }
    //父进程更新数据库
    updatedb();
    //解除对2号信号的屏蔽
    printf("%d进程:解除对%d号信号屏蔽\n",getpid(),signum);
    if(sigprocmask(SIG_SETMASK,&old,NULL) == -1){
        perror("sigprocmask");
        return -1;
    }

    for(;;);
    return 0;
}






