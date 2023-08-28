//写冲突
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
    // ./a.out hello    
    //打开文件
    int fd = open("./conf.txt",
                O_WRONLY | O_CREAT | O_APPEND,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //向文件中写入数据
    for(int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i]))==-1){
            perror("write");
            return -1;
        }
        sleep(1);
    }
    //关闭文件
    close(fd);
    return 0;
}



