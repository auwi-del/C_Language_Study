#include <stdio.h>


// �ж��ǲ������� ����, ����һ��int, ���� 1����, 0ƽ��
int isRunNian( int year )
{
    if( year % 400 == 0 || ( (year % 4 == 0) && (year % 100 != 0) ) )
        return 1;
    else
        return 0;
}

int main()
{
    // pointerM : ��ǰ�����ۼ���һ����
    int i, j, y, m, pointerM, d, ans;
    int pingNian[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int runNian[] =  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while( scanf( "%d/%d/%d", &y, &m, &d ) != EOF )
    {
        ans = 0;
        // �ӵ�һ���¿�ʼ�ۼ�, �����ۼ����һ����, ��Ϊ�Ǹ���û����
        for( pointerM = 1; pointerM < m; pointerM++ )
        {
            if( isRunNian( y ) )
                ans += runNian[pointerM];
            else
                ans += pingNian[pointerM];
        }
        
        // ���������һ���µ�����, �� d
        ans += d;
        // ��ӡ����, ע���ӡ��ʽ��! ĩβҪ���� \n ��!
        printf( "%d\n", ans );
    }
}