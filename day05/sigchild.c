//太平间信号
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<errno.h>
//信号处理函数,负责收尸
void sigchild(int signum){
    printf("%d进程:捕获到%d号信号\n",getpid(),signum);
    sleep(2);//假装耗时
    for(;;){
        pid_t pid = waitpid(-1,NULL,WNOHANG);
        if(pid == -1){
            if(errno == ECHILD){
                printf("%d进程:没有子进程\n",getpid());
                break;
            }else{
                perror("waitpid");
                return;
            }
        }else if(pid == 0){
            printf("%d进程:子进程在运行\n",getpid());
            break;
        }else{
            printf("%d进程:回收了%d\n",getpid(),pid);
        }
    }


    /*for(;;){
        pid_t pid = wait(NULL);
        if(pid == -1){
            if(errno == ECHILD){
                printf("没有子进程了\n");
                break;
            }else{
                perror("wait");
                return;// exit(0);
            }
        }
        printf("%d进程:回收了%d进程\n",getpid(),pid);
    }*/
}

int main(void){
    //对17号信号进行捕获处理
    if(signal(SIGCHLD,sigchild) == SIG_ERR){
        perror("signal");
        return -1;
    } 
    //父进程创建多个子进程
    for(int i = 0;i < 5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            //sleep(i + 1);
            sleep(1);
            return 0;
        }
    }
    //创建老六
    pid_t oldsix = fork();
    if(oldsix == -1){
        perror("fork");
        return -1;
    }
    if(oldsix == 0){
        printf("%d进程:我是老六,略略略...\n",getpid());
        sleep(15);
        return 0;
    }
    
    //父进程该干嘛干嘛
    for(;;);
    return 0;
}





