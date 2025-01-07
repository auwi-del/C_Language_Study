/* HDU2023 ��ƽ���ɼ� */

#include <stdio.h>
#include <string.h>

#define N 50
#define M 5
//     ��ϸ����      ÿ��ѧ�����ܷ�   ����ѧ���� M ��Ŀ�ķ���֮��, ��������˿�Ŀ��ƽ����
double score[N][M], rowsum[N],      colaverage[M];

int main(void)
{
    int n, m, i, j;

    while(~scanf("%d%d", &n, &m)) {
        /* ��ʼ�� */
        memset(rowsum, 0, sizeof(rowsum));
        memset(colaverage, 0, sizeof(colaverage));

        /* �������ݲ���� */
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%lf", &score[i][j]);             // ��ȡ�� i ��ѧ�� �� j ��

                /* ��� */  
                rowsum[i] += score[i][j];               // i ѧ�����ܷ� += ��ǰ����
                colaverage[j] += score[i][j];           // j ��Ŀ������ += ��ǰ����
            }
        }

        /* ���n��ѧ����ƽ���ɼ� */
        for (i = 0; i < n; i++) {
            if(i != 0) printf(" ");                     // ��ֹ������ո�, ���Բ��� printf( ".2f ", ... );
            printf("%.2f", rowsum[i] / m);              // ÿ��ѧ�����ܷ� / ��Ŀ����m == ѧ��ƽ����
        }
        printf("\n");

        /* ������ſε�ƽ���ɼ� */
        for (i = 0; i < m; i++) {
            colaverage[i] /= n;                         // <-------- ע��, ������һ��, ������ĺ����Ϊ��ÿ�ſ�Ŀ��ƽ����
            if(i != 0) printf(" ");
            printf("%.2f", colaverage[i]);
        }
        printf("\n");

        /* ͳ�Ƹ��Ƴɼ�������ƽ���ɼ���ѧ������ */
        int cnt = 0, mc;
        for (i = 0; i < n; i++) {                       // i ��ѧ��, j �ſ�Ŀ�����
            mc = 0;                                     // ��ǰ����, �ɼ�����ƽ���ɼ��Ŀ�Ŀ���� 
            for (j = 0; j < m; j++) {
                if (score[i][j] < colaverage[j]) break;
                else mc++;
            }
            if (mc == m) 
                cnt++;
        }

        /* ������Ƴɼ�������ƽ���ɼ���ѧ������ */
        printf("%d\n\n", cnt);
    }

    return 0;
}
