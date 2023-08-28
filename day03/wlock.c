//文件锁解决写冲突
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc,char* argv[]){
    // ./a.out hello    
    //打开文件
    int fd = open("./conf.txt",
                O_WRONLY | O_CREAT | O_APPEND,0664);
    if(fd == -1){
        perror("open");
        return -1;
    }
    //阻塞方式加锁
    struct flock l;//代表锁的详细信息
    l.l_type = F_WRLCK;//写锁
    l.l_whence = SEEK_SET;
    l.l_start = 0;
    l.l_len = 0;//一直锁到文件尾
    l.l_pid = -1;
    /*if(fcntl(fd,F_SETLKW,&l) == -1){
        perror("fcntl");
        return -1;
    }*/
    //非阻塞方式加锁
    while(fcntl(fd,F_SETLK,&l) == -1){
        if(errno == EACCES || errno == EAGAIN){
            printf("文件被锁定,干点别的去...\n");
            sleep(1);
        }else{
            perror("fcntl");
            return -1;
        }
    }

    //向文件中写入数据
    for(int i = 0;i < strlen(argv[1]);i++){
        if(write(fd,&argv[1][i],sizeof(argv[1][i]))==-1){
            perror("write");
            return -1;
        }
        sleep(1);
    }

    //解锁
    struct flock ul;//代表锁的详细信息
    ul.l_type = F_UNLCK;//解锁
    ul.l_whence = SEEK_SET;
    ul.l_start = 0;
    ul.l_len = 0;//一直锁到文件尾
    ul.l_pid = -1;
    if(fcntl(fd,F_SETLK,&ul) == -1){
        perror("fcntl");
        return -1;
    }
    //关闭文件
    close(fd);
    return 0;
}



