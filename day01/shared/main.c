//使用库文件
#include<stdio.h>
//#include"calc.h"// add()  sub()
//#include"show.h"// show()
#include"math.h"
int main(void){
    double a = 123,b = 456;
    double res = add(a,b);
    show(a,'+',b,res);
    show(a,'-',b,sub(a,b));
    return 0;
}
