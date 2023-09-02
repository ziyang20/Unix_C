// fork + exec
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
    //子进程变身!
    if(pid == 0){
        if(execl("./new","new","hello","123",NULL) == -1){
            perror("execl");
            return -1;
        }
        //return 0;
    }
    //父进程收尸!
    int s;//用来输出子进程的终止状态
    if(waitpid(pid,&s,0) == -1){
        perror("waitpid");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    
    //创建第二个子进程
    pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //第二个子进程变身
    if(pid == 0){
        if(execlp("ls","ls","-l","-i",NULL) == -1){
            perror("execlp");
            return -1;
        }
        //return 0;
    }   
    //收尸
    if(waitpid(pid,&s,0) == -1){
        perror("waitpid");
        return -1;
    }
    if(WIFEXITED(s)){
        printf("正常终止:%d\n",WEXITSTATUS(s));
    }else{
        printf("异常终止:%d\n",WTERMSIG(s));
    }
    return 0;
}









