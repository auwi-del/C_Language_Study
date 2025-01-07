#include <stdio.h>

struct Date
{
    int year, month, day;
} date1, date2;

// 1.1.1 -> 1949.10.1 = 711765
// 1.1.1 -> 2023.10.1 = 738793
// 1949.10.1 -> 2023.10.1 = 27028

// 1.1.1 -> 11.1.1 = 3652

// �����һ�����
int getTheDate( struct Date* );
int getNumber( int*, int, int );
int dateCalculation( struct Date*, struct Date* );
int dayInMonth( int, int );
int dayInYear( int );

int main()
{
    int i, j, k;                                // ��������
    date1 = (struct Date) { 1949, 10, 1};
    date2 = (struct Date) { 2023, 10, 1};
    // ��ȡ����:
    printf("--------------------\n�������һ����:\n");
    getTheDate(&date1);                         // ��һ��������    
    while(1)                                    // �ڶ����� ��ȷ�Լ��
    {
        printf("\n--------------------\n����������ڶ�����:\n");
        getTheDate(&date2);
        
        if(date1.year >= date2.year)
            if(date1.month >= date2.month)
                if(date1.day > date2.day)
                    printf("\n�������ڴ��ڵ�һ����.");          // ������������, һ��������������
        break;
    }
    printf("--------------------\n");
    printf("��һ����: %d-%d-%d\n", date1.year, date1.month, date1.day);
    printf("�ڶ�����: %d-%d-%d\n", date2.year, date2.month, date2.day);
    printf("--------------------\n");

    printf( "\n������, �����ھ���һ���� %d ��\n\n", dateCalculation(&date1, &date2) );
    system( "pause" );
}
// ���ڼ���, ��������struct Date��ָ��
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
// �������ȡ����, Ӧ���� {��, ��, ��} ����ĵ�ַ.
int getTheDate(struct Date *p)
{
    printf("\n���������:  ");
    getNumber( &(p->year), 1, 2100);
    printf("�������·�:  ");
    getNumber( &(p->month), 1, 12);
    printf("����������:  ");
    getNumber( &(p->day), 1, dayInMonth( p->year, p->month ) );
}
// ��ȡ��ֵ�ķ���, ����(��ַ, ����, ����)
int getNumber(int *number, int min ,int max)
{
    while(1)
    {
        scanf("%d", number);
        if(*number >= min && *number <= max)
            return 1;
        else
            printf("������ֵ����, ����������:  ");
    }
}
// ���� ���(int), �·�(int), ����һ�����µ�����(int)
int dayInMonth(int year, int month)
{
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        daysInMonth[2]++;
    return daysInMonth[month];
}
// ���� ���(int), ����һ�����������(int)
int dayInYear(int year)
{
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        return 366;
    else return 365;
}