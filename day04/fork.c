//子进程的创建
#include<stdio.h>
#include<unistd.h>

int main(void){
    printf("%d进程:我是父进程\n",getpid());
    //创建子进程
    pid_t a = fork();
    if(a == -1){
        perror("fork");
        return -1;
    }
    //子进程
    if(a == 0){
        printf("%d进程:这是子进程代码\n",getpid());
        return 0;
    }
    //父进程
    printf("%d进程:这是父进程代码\n",getpid());
    return 0;

    /*if(a == 0){
        printf("%d进程:锅包肉\n",getpid());
        return 0;
    }else{
        printf("%d进程:地三鲜\n",getpid());
        return 0;
    }
    
    printf("%d进程:铁锅炖大鹅\n",getpid());
    return 0;*/
}
