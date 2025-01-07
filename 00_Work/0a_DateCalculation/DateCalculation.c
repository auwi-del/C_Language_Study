#include <stdio.h>
int getTheDate( int*);
int getNumber(int*, int, int);
int dateCalculation(int *, int *);
int dayInMonth(int, int);
int dayInYear(int);

int main()
{
    int i, j, k;                                // 计数变量
    int date1[3] = {1996, 2, 28}, date2[3] = {1997, 5, 20}; // date[] = {年, 月, 日}, 这里预留的默认值答案应该是447天

    // 获取输入部分  
    printf("--------------------\n请输入第一日期:\n");
    getTheDate(date1);                          // 第一日期输入    
    while(1)                                    // 第二日期 正确性检测
    {
        printf("\n--------------------\n下面请输入第二日期:\n");
        getTheDate(date2);
        
        if(date1[0] >= date2[0])
            if(date1[1] >= date2[1])
                if(date1[2] > date2[2])
                    printf("\n输入日期大于第一日期.");          // 程序来到这里, 一定是日期有问题
        break;
    }
    printf("--------------------\n");
    printf("第一日期: %d-%d-%d\n", date1[0], date1[1], date1[2]);
    printf("第二日期: %d-%d-%d\n", date2[0], date2[1], date2[2]);
    printf("--------------------\n");

    printf( "\n经计算, 两日期距离一共有%d天", dateCalculation(date1, date2) );
}
// 2014.10.1 ~ 2023.5.6  =  3139
// 日期计算, 传入两个日期的指针
int dateCalculation(int *date1, int *date2)
{
    int s = 0;
    int year = date1[0], month = date1[1], day = date1[2];
    int year2 = date2[0], month2 = date2[1], day2 = date2[2];

    for(; year < date2[0]; year++)      // 年只加不减
        s += dayInYear(year);

    for(; month < date2[1]; month++)    // 月可加可减
        s += dayInMonth(year, month);
    for(; date2[1] < month; month--)    // date1[1] > date2[1] 的情况
        s -= dayInMonth(year, month);

    for(; day < date2[2]; day++)        // 日
        s++;
    for(; date2[2] < day; day--)        // date1[2] > date2[2] 的情况
        s--;
    return s;
}

// 从输入读取日期, 应传入 {年, 月, 日} 数组的地址.
int getTheDate(int *p)
{
    printf("\n请输入年份:  ");
    getNumber(p, 1949, 2049);
    printf("请输入月份:  ");
    getNumber(p+1, 1, 12);
    printf("请输入日期:  ");
    getNumber(p+2, 1, dayInMonth(p[0], p[1]) );
}

// 获取数值的方法, 传入(地址, 下限, 上限)
int getNumber(int *number, int min ,int max)
{
    while(1)
    {
        scanf("%d", number);
        if(*number >= min && *number <= max)
            return 1;
        else printf("输入数值有误, 请重新输入:  ");
    }
}

// 输入 年份(int), 月份(int), 返回一个当月的日期(int)
int dayInMonth(int year, int month)
{
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        daysInMonth[2]++;
    return daysInMonth[month];
}

// 输入 年份(int), 返回一个当年的日期(int)
int dayInYear(int year)
{
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        return 366;
    else return 365;
}