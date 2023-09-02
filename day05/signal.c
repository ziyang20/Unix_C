//信号处理
#include<stdio.h>
#include<unistd.h>
#include<signal.h>// signal()
typedef void (*sighandler_t)(int);
//信号处理函数
void sigfun(int signum){
    printf("捕获到%d号信号\n",signum);
}
int main(void){
    //对2号信号进行忽略处理
    sighandler_t res = signal(SIGINT,SIG_IGN);
    if(res == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("res = %p\n",res);
    //对2号信号进行捕获处理
    res = signal(SIGINT,sigfun);
    if(res == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("res = %p\n",res);
    //对2号信号恢复默认处理
    res = signal(SIGINT,SIG_DFL);
    if(res == SIG_ERR){
        perror("signal");
        return -1;
    }
    printf("res = %p\n",res);

    for(;;);
    return 0;
}



