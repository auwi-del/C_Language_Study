/* Note:Your choice is C IDE */
#include "stdio.h"

// ������һ���ṹ, ��Ϊ Date
struct Date
{
	int year;
	int month;
	int day;
};

// ����һ������ (int)���, ����һ�������Ƿ�Ϊ����, ��(1), ��(0)
int Is_Leap_Year( int year )
{
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        return 1;
    else return 0;
}

// ���δ���( ����������ֵ, ��������Сֵmin, ���������ֵmax ), �˺��������ֵ�Ƿ����� [min, max]������ ֮�еĺ���, ����: ��(1), ��(0)
int checkNum( int num, int min, int max )
{
    if( num >= min && num <= max )
        return 1;
    else
        return 0;
}

// ���δ���( ���year, �·�month ), �˺������� year ��� month ���ж�����
int dayInMonth(int year, int month)
{
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        daysInMonth[2]++;
    return daysInMonth[month];
}

// ����Ҫд�����ݵ� struct Date���� �ĵ�ַ, �˺���Ӧ��֤�ڵ��ñ�������, д�����ֵ������ȷ��
int getTheDate(struct Date *p)
{
    while(1)
    {
        printf( "\n����������( ��ʽ: year-month-day ):\n");
        scanf( "%d-%d-%d", &(p->year), &(p->month), &(p->day) );

        // ���ݽ����ж�, ���ж���, ��Ҫ��֤���ǶԵ�, ���ж���, Ҫ��֤���ǶԵ�
        if( checkNum( p->year, 1, 2200 ) )
            if( checkNum( p->month, 1, 12 ) )
                if( checkNum( p->day, 1, dayInMonth( p->year, p->month ) ) )
                    break;

        printf( "\n��������, ���鲢��������.\n");
    }   
}
   



int main()
{
    struct Date D1,D2;                      // ���̳������� �ṹ����,  ������Ϊ struct Date.

    int a1[12]={31,28,31,30,31,30,31,31,30,31,30,31};               // ƽ���ÿ���¶��м���
    int a2[12]={31,29,31,30,31,30,31,31,30,31,30,31};               // �����ÿ���¶��м���

/*===================================================================
    ��������
        ����������int�ı���, 
        x �� a �ֱ�����ͳ�� ��һ���������ڵ� ��ݵ����� �� ÿ�µ�����
===================================================================*/
    int day=0, day1=0, day2=0, x=0, y=0, a=0, b=0, i;


//========�����õĴ���====
    // D1 = (struct Date ) { 1949, 10, 1 };
    // D2 = (struct Date ) { 2023, 10, 1 };



//=====�µ�����ģ��, �ܹ������û������Ƿ���ȷ
    printf("--------------------------------------------\n�������һ����:\n");
    getTheDate(&D1);                            // ��һ��������    
    printf("--------------------------------------------\n������ڶ�����:\n");
    getTheDate(&D2);

    printf("--------------------\n");
    printf("��һ����: %d-%d-%d\n", D1.year, D1.month, D1.day);
    printf("�ڶ�����: %d-%d-%d\n", D2.year, D2.month, D2.day);
    printf("--------------------\n");


//================================================================================================
//================================================================================================
//
//                           ��  ��  D 1  ��  ��  ��
//                      x : ��ԪԪ��һ��һ�յ�����һ��һ�յ�����
//                      a : ����һ��һ�յ�����һ�յ�����
//
//================================================================================================
//================================================================================================

    // ����� ��ԪԪ�� ����һ������(D1.year), ֻ����Ļ��ж�����, 
    // _________________  �ۼӵ����� x ��!  _________________

    for( i=1; i < D1.year; i++ )
    {
        // ��������:
        if( Is_Leap_Year( i ) )
        {
            x += 366;           // ���� 366 ��
        }
        else 
        {
            x += 365;           // else, ����ƽ��, ���� 365 ��
        }
    }


    // ����� ��һ���ڵ����(D1.year) �� 1��1��, ����һ���ڵ� ĳ��1��(D1.month) �ж�����, 
    // _______________________________  �ۼӵ����� a ��!  _______________________________

    for( i = 0; i < D1.month - 1; i++ )
    {
        // ���������:
        if( Is_Leap_Year( D1.year ) )
        {
            a += a1[i];             // �ۼ�ÿ�µ�����( ����� )
        }

        else
        {
            a += a2[i];             // �ۼ�ÿ�µ�����( ƽ��� )
        }
    }





//================================================================================================
//================================================================================================
//
//                      Ȼ �� �� �� �� D 2 �� �� ��
//                      �ɸ����Ϸ��Ĵ���, Ȼ���D1, �ĳ�D2,
//                      Ȼ��� x ��Ϊ y, a ��Ϊ b.
//
//================================================================================================
//================================================================================================




    // ����� ��ԪԪ�� ���ڶ�������(D2.year), ֻ����Ļ��ж�����, 
    // _________________  �ۼӵ����� y ��!  _________________
    for( i=1; i < D2.year; i++ )
    {
        // ��������
        if( Is_Leap_Year( i ) )
        {   
            y += 366;           // ���� 366 ��
        }
        else
        {
            y += 365;           // else, ����ƽ��, ���� 365 ��    
        }
    }


    // ����� �ڶ����ڵ����(D2.year) �� 1��1��, ���ڶ����ڵ� ĳ��1��(D2.month) �ж�����, 
    // _______________________________  �ۼӵ����� b ��!  _______________________________

    for( i=0; i < D2.month - 1; i++ ) 
    {

        if( Is_Leap_Year( D2.year ) )
        {
            b += a2[i];             // �ۼ�ÿ�µ�����( ����� )
        }
        else
        {
            b += a2[i];             // �ۼ�ÿ�µ�����( ƽ��� )
        }
    }






//================================================================================================
//================================================================================================
//
//                        ��     ��     ��     ��     ��
//
//================================================================================================
//================================================================================================

//  1��1��1�յ���������� 
//    = ��ԪԪ��һ��һ�յ�����һ��һ�յ�����( x����y ) 
//      + ����һ��һ�յ�����һ�յ�����( a����b ) 
//      + ���µĵڼ��� 
    day1 = x + a + D1.day;
    day2 = y + b + D2.day;


// �������, ��������(day).
    day=day1-day2;


// ����û����뷴��, ������Ǹ���, ������ľ���
    if(day<0)
    {
        day=-day;
    }


// ���
    printf("���%d��\n\n",day);
    system( "pause" );

}