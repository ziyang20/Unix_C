//子进程的回收
#include<stdio.h>
#include<stdlib.h>// exit()
#include<unistd.h>
#include<sys/wait.h>// wait()

int main(void){
    //父进程创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程暂时不结束
    if(pid == 0){
        printf("%d进程:我是子进程,暂时不结束\n",getpid());
        //sleep(5);
        //return 300;
        //exit(0);
        //_exit(0);
        //_Exit(0);
        //abort();
        int* p = NULL;
        *p = 123;
    }
    //父进程,等待收尸
    printf("%d进程:等待子进程结束并收尸\n",getpid());
    int s;//用来输出子进程的终止状态
    pid_t childpid = wait(&s);
    if(childpid == -1){
        perror("wait");
        return -1;
    }
    printf("%d进程:回收了%d进程僵尸\n",getpid(),childpid);
    
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    return 0;
}




