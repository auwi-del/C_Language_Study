#include <stdio.h>

int main(){
    int a;
    int i;
    printf("请输入菜单数字:\n");
    printf("=================\n");
    printf("1. 骂你100次\n");
    printf("2. 骂你200次\n");
    printf("3. 骂你300次\n");
    printf("4. 骂你400次\n");
    printf("5. 骂你500次\n");
    printf("6. 骂你600次\n");
    printf("=================\n");

    scanf("%d", &a);
    printf("值为:%d", a);

    for(i=0;i<a*100;i++){
        printf("sb, %d!     ", i);
    }

    
}