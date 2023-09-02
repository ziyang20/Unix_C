//创建新进程
#include<stdio.h>
#include<unistd.h>

// ./new hello world 1234
int main(void){
    printf("%d进程:我要变身了\n",getpid());
    /*if(execl("./new","./new","hello","world","1234",NULL)){
        perror("execl");
        return -1;
    }*/
    /*if(execl("/bin/ls","ls","-l","-i",NULL) == -1){
        perror("execl");
        return -1;
    }*/
    /*if(execlp("ls","ls","-l","-i",NULL) == -1){
        perror("execlp");
        return -1;
    }*/
    char* envp[] = {"NAME=laozhang","AGE=18",
                    "FOOD=guobaorou",NULL};
    /*if(execle("./new","new","hello",NULL,envp) == -1){
        perror("execle");
        return -1;
    }*/
    char* argv[] = {"new","hello","123",NULL};
    if(execve("./new",argv,envp) == -1){
        perror("execve");
        return -1;
    }
    printf("%d进程:变身完成了\n",getpid());
    return 0;
}




