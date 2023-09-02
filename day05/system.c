//system函数演示
#include<stdio.h>
#include<stdlib.h>// system
#include<sys/wait.h>
int main(void){
    int s = system("./new hello 123");
    if(s == -1){
        perror("system");
        return -1;
    }
    if(WIFSIGNALED(s)){
        printf("异常结束:%d\n",WTERMSIG(s));
    }else{
        printf("正常结束:%d\n",WEXITSTATUS(s));
    }

    s = system("ls -l -i --color=auto");
    if(s == -1){
        perror("system");
        return -1;
    }
    if(WIFSIGNALED(s)){
        printf("异常结束:%d\n",WTERMSIG(s));
    }else{
        printf("正常结束:%d\n",WEXITSTATUS(s));
    }
    return 0;
}
