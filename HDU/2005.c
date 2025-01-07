#include <stdio.h>


// 判断是不是闰年 函数, 传入一个int, 返回 1闰年, 0平年
int isRunNian( int year )
{
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        return 1;
    else
        return 0;
}

int main()
{
    // pointerM : 当前正在累加哪一个月
    int i, j, y, m, pointerM, d, ans;
    int pingNian[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int runNian[] =  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while( scanf( "%d/%d/%d", &y, &m, &d ) != EOF )
    {
        ans = 0;
        // 从第一个月开始累加, 并不累加最后一个月, 因为那个月没过完
        for( pointerM = 1; pointerM < m; pointerM++ )
        {
            if( isRunNian( y ) )
                ans += runNian[pointerM];
            else
                ans += pingNian[pointerM];
        }
        
        // 最后加上最后一个月的天数, 即 d
        ans += d;
        // 打印出来, 注意打印格式奥! 末尾要加上 \n 奥!
        printf( "%d\n", ans );
    }
}