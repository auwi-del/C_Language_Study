#include <stdio.h>

struct Date
{
    int year, month, day;
} date1, date2;

// 1.1.1 -> 1949.10.1 = 711765
// 1.1.1 -> 2023.10.1 = 738793
// 1949.10.1 -> 2023.10.1 = 27028

// 1.1.1 -> 11.1.1 = 3652

// 这块这一大堆是
int getTheDate( struct Date* );
int getNumber( int*, int, int );
int dateCalculation( struct Date*, struct Date* );
int dayInMonth( int, int );
int dayInYear( int );

int main()
{
    int i, j, k;                                // 计数变量
    date1 = (struct Date) { 1949, 10, 1};
    date2 = (struct Date) { 2023, 10, 1};
    // 获取输入:
    printf("--------------------\n请输入第一日期:\n");
    getTheDate(&date1);                         // 第一日期输入    
    while(1)                                    // 第二日期 正确性检测
    {
        printf("\n--------------------\n下面请输入第二日期:\n");
        getTheDate(&date2);
        
        if(date1.year >= date2.year)
            if(date1.month >= date2.month)
                if(date1.day > date2.day)
                    printf("\n输入日期大于第一日期.");          // 程序来到这里, 一定是日期有问题
        break;
    }
    printf("--------------------\n");
    printf("第一日期: %d-%d-%d\n", date1.year, date1.month, date1.day);
    printf("第二日期: %d-%d-%d\n", date2.year, date2.month, date2.day);
    printf("--------------------\n");

    printf( "\n经计算, 两日期距离一共有 %d 天\n\n", dateCalculation(&date1, &date2) );
    system( "pause" );
}
// 日期计算, 传入两个struct Date的指针
int dateCalculation(struct Date *dp1, struct Date *dp2)
{
    int s = 0;
    int year1 = dp1->year, month1 = dp1->month, day1 = dp1->day;

    for(; year1 < date2.year; year1++)
        s += dayInYear(year1);
    for(; month1 < date2.month; month1++)
        s += dayInMonth(year1, month1);
    for(; day1 < date2.day; day1++)
        s++;
    for(; date2.day < day1; day1--)
        s--;
    return s;
}
// 从输入读取日期, 应传入 {年, 月, 日} 数组的地址.
int getTheDate(struct Date *p)
{
    printf("\n请输入年份:  ");
    getNumber( &(p->year), 1, 2100);
    printf("请输入月份:  ");
    getNumber( &(p->month), 1, 12);
    printf("请输入日期:  ");
    getNumber( &(p->day), 1, dayInMonth( p->year, p->month ) );
}
// 获取数值的方法, 传入(地址, 下限, 上限)
int getNumber(int *number, int min ,int max)
{
    while(1)
    {
        scanf("%d", number);
        if(*number >= min && *number <= max)
            return 1;
        else
            printf("输入数值有误, 请重新输入:  ");
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