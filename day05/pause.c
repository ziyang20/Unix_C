//pause函数演示
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//信号处理函数
void sigfun(int signum){
    printf("%d号信号处理开始\n",signum);
    sleep(3);
    printf("%d号信号处理结束\n",signum);
}
int main(void){
    //堆2号信号进行捕获处理
    if(signal(SIGINT,sigfun) == SIG_ERR){
        perror("signal");
        return -1;
    }
    //睡觉
    int res = pause();
    printf("pause函数返回%d\n",res);
    return 0;
}





