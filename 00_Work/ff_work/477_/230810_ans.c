#include <stdio.h>

//a为存放待组合的数值。b为用于暂存的数组
//n. m代表从n中取出m个数的组合
// M=m M用于输出
void c(int a[],int b[],int n, int m,const int M){
    if (m>0){
        for (int i=n; i>=m; i--){
            b[m-1]=a[i-1];
            //由于确定了当前位置的值
            //则下次递归c(n-1,m-1)
            c(a,b,i-1,m-1,M);
        }
    }
    else{
        for (int i=0; i<M; i++)
            printf("%d", b[i] );
            // cout<<b[i]<<"";
        printf("\n");
    }

}
int main(){
    int arr[]= {0,1,2,3,4,5,6};
    int b[7];
    c(arr,b,7,5,5);
    return 0;
}
