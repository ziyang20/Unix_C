//显示模块实现
#include<stdio.h>
#include"show.h"

//显示等式
void show(double l,char op,double r,double res){
    printf("%lg %c %lg = %lg\n",l,op,r,res);
}
