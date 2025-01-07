/* HDU2023 求平均成绩 */

#include <stdio.h>
#include <string.h>

#define N 50
#define M 5
//     详细分数      每名学生的总分   所有学生第 M 科目的分数之和, 后来变成了科目的平均分
double score[N][M], rowsum[N],      colaverage[M];

int main(void)
{
    int n, m, i, j;

    while(~scanf("%d%d", &n, &m)) {
        /* 初始化 */
        memset(rowsum, 0, sizeof(rowsum));
        memset(colaverage, 0, sizeof(colaverage));

        /* 输入数据并求和 */
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%lf", &score[i][j]);             // 获取第 i 个学生 第 j 科

                /* 求和 */  
                rowsum[i] += score[i][j];               // i 学生的总分 += 当前分数
                colaverage[j] += score[i][j];           // j 科目分数和 += 当前分数
            }
        }

        /* 输出n个学生的平均成绩 */
        for (i = 0; i < n; i++) {
            if(i != 0) printf(" ");                     // 防止多输出空格, 所以不用 printf( ".2f ", ... );
            printf("%.2f", rowsum[i] / m);              // 每个学生的总分 / 科目数量m == 学生平均分
        }
        printf("\n");

        /* 输出各门课的平均成绩 */
        for (i = 0; i < m; i++) {
            colaverage[i] /= n;                         // <-------- 注意, 经过这一步, 此数组的含义变为了每门科目的平均分
            if(i != 0) printf(" ");
            printf("%.2f", colaverage[i]);
        }
        printf("\n");

        /* 统计各科成绩均大于平均成绩的学生数量 */
        int cnt = 0, mc;
        for (i = 0; i < n; i++) {                       // i 名学生, j 门科目的情况
            mc = 0;                                     // 当前行中, 成绩大于平均成绩的科目数量 
            for (j = 0; j < m; j++) {
                if (score[i][j] < colaverage[j]) break;
                else mc++;
            }
            if (mc == m) 
                cnt++;
        }

        /* 输出各科成绩均大于平均成绩的学生数量 */
        printf("%d\n\n", cnt);
    }

    return 0;
}
