//文件的元数据
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<sys/stat.h>// stat()
// 转换类型和权限的串
// hello.txt -> stat() -> s.st_mode -> mtos() -> -rwxrwxr-x
char* mtos(mode_t m){
    static char s[11] = {};
    if(S_ISDIR(m)){
        strcpy(s,"d");
    }else
    if(S_ISSOCK(m)){
        strcpy(s,"s");
    }else
    if(S_ISBLK(m)){
        strcpy(s,"b");
    }else
    if(S_ISCHR(m)){
        strcpy(s,"c");
    }else
    if(S_ISFIFO(m)){
        strcpy(s,"p");
    }else
    if(S_ISLNK(m)){
        strcpy(s,"l");
    }else{
        strcpy(s,"-");
    }
    //判断权限
    strcat(s,m & S_IRUSR ? "r" : "-");
    strcat(s,m & S_IWUSR ? "w" : "-");
    strcat(s,m & S_IXUSR ? "x" : "-");
    strcat(s,m & S_IRGRP ? "r" : "-");
    strcat(s,m & S_IWGRP ? "w" : "-");
    strcat(s,m & S_IXGRP ? "x" : "-");
    strcat(s,m & S_IROTH ? "r" : "-");
    strcat(s,m & S_IWOTH ? "w" : "-");
    strcat(s,m & S_IXOTH ? "x" : "-");
    return s;
}
// 时间转换
char* ttos(time_t t){
    static char time[20] = {};
    struct tm* l = localtime(&t);
    sprintf(time,"%d-%d-%d %d:%d:%d",l->tm_year+1900,
            l->tm_mon+1,l->tm_mday,l->tm_hour,
            l->tm_min,l->tm_sec);
    return time;
}

int main(int argc,char* argv[]){
    // ./a.out  hello.txt
    struct stat s;//用来输出文件的元数据
    if(stat(argv[1],&s) == -1){
        perror("stat");
        return -1;
    }
    printf("        设备ID:%ld\n",s.st_dev);
    printf("       i节点号:%ld\n",s.st_ino);
    printf("    类型和权限:%s\n",mtos(s.st_mode));
    printf("      硬链接数:%lu\n",s.st_nlink);
    printf("        用户ID:%u\n",s.st_uid);
    printf("          组ID:%u\n",s.st_gid);
    printf("    特殊设备ID:%ld\n",s.st_rdev);
    printf("      总字节数:%ld\n",s.st_size);
    printf("    IO块字节数:%ld\n",s.st_blksize);
    printf("      存储块数:%ld\n",s.st_blocks);
    printf("  最后访问时间:%s\n",ttos(s.st_atime));
    printf("  最后修改时间:%s\n",ttos(s.st_mtime));
    printf("  最后改变时间:%s\n",ttos(s.st_ctime));
    return 0;
}






