//子进程是父进程的副本
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int global = 10;//数据区

int main(void){
    int local = 20;//栈区
    int* heap = malloc(sizeof(int));//堆区
    *heap = 30;
    printf("%d进程:%p:%d %p:%d %p:%d\n",getpid(),
            &global,global,&local,local,heap,*heap);
    //创建子进程
    pid_t pid = fork();
    if(pid == -1){
        perror("fork");
        return -1;
    }
    //子进程代码
    if(pid == 0){
        printf("%d进程:%p:%d %p:%d %p:%d\n",getpid(),
            &global,++global,&local,++local,heap,++*heap);
        return 0;
    }
    //父进程代码
    sleep(1);//延时,等子进程先执行结束
    printf("%d进程:%p:%d %p:%d %p:%d\n",getpid(),
            &global,global,&local,local,heap,*heap);
    return 0;
}




