//内存映射
#include<stdio.h>
#include<string.h>
#include<sys/mman.h>

int main(void){
    //找内存要空间,建立虚拟地址和物理地址的映射
    char* start = mmap(NULL,8192,
            PROT_READ | PROT_WRITE,
            MAP_PRIVATE | MAP_ANONYMOUS,0,0);
    if(start == MAP_FAILED){
        perror("mmap");
        return -1;
    }
    //通过虚拟地址即可访问内存
    strcpy(start,"铁锅炖大额");
    printf("%s\n",start);
    //解除虚拟地址和物理地址的映射关系
    if(munmap(start,4096) == -1){
        perror("munmap");
        return -1;
    }
    //printf("%s\n",start); //段错误
        
    //计算第二个页的起始虚拟地址
    char* start2 = start + 4096;
    strcpy(start2,"小鸡炖蘑菇");
    printf("%s\n",start2);
    //解除第二个页的映射
    if(munmap(start2,4096) == -1){
        perror("munmap");
        return -1;
    }
    
    //printf("%s\n",start2);段错误
    return 0;
}





