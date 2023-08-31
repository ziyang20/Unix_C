//回收多个子进程
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<errno.h>

int main(void){
    //创建多个子进程
    for(int i = 0;i < 5;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return -1;
        }
        if(pid == 0){
            printf("%d进程:我是子进程\n",getpid());
            sleep(1 + i);
            return 0;
        }
    }
    //回收多个子进程
    for(;;){
        pid_t pid = wait(NULL);
        if(pid == -1){
            if(errno == ECHILD){
                printf("%d进程:没有子进程了\n",getpid());
                break;
            }else{
                perror("wait");
                return -1;
            }
        }
        printf("%d进程:回收了%d进程僵尸\n",getpid(),pid);
    }
    return 0;
}




