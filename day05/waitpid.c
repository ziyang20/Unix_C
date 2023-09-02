//非阻塞方式收尸
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程执行,暂时不结束
    if(pid == 0){
        printf("%d进程:你来收我呀\n",getpid());

        return 0;
    }
    //父进程,非阻塞方式收尸
    for(;;){
        pid_t childpid = waitpid(pid,NULL,WNOHANG);
        if(childpid == -1){
            perror("waitpid");
            return -1;
        }else if(childpid == 0){
            printf("%d进程:收不了,干点别的去\n",getpid());
            sleep(1);
        }else{
            printf("%d进程:回收了%d的僵尸\n",
                        getpid(),childpid);
            break;
        }
    }
    return 0;
}




