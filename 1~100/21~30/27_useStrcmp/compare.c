#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    float x,y,a;
    for (y=1.5;y>-1.5;y-=0.1){              //y坐标递增
        for (x=-1.5;x<1.5;x+=0.05){         //x坐标递增
            //( (x^2 +y^2)-1)^3 - (x^2)*(y^3) ) <= 误差范围
             a = x * x + y * y - 1;

             // [条件语句] ? [语句a] : [语句b]
             // 解释:
             //   条件符合, 表达式的值=[语句a]; 条件不符合, 表达式的值=[语句b] 
             putchar(a * a * a- x * x * y * y * y <=0.0001? '*': ' ');
        }
        // system("color 0c");              //调成终端颜色, 用不到
        putchar('\n');
    }
    printf("\n\n");
    return 0;
}
