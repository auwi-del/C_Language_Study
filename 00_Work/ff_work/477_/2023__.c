/*
Problem Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
 

Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。
 

Output
对于每个测试实例，输出3行数据，第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。
 

Sample Input

2 2
5 10
10 20

 

Sample Output

7.50 15.00
7.50 15.00
1
*/




#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,c=0,count=0,n,m;    // i,j: 计数变量; count: 统计高于平均分学生数量; n学生数量; m科目数量
    double student[51][6];        // 学生的各科成绩,s是每个人总分数,n个学生，m个科目
    double class_total[6];       // 每门课的总成绩
    double s;                   // 所有学生的总成绩之和

    

    while( scanf( "%d %d", &n, &m ) != EOF )    // 
    {
        count = 0;                              // 高于平均分学生数量归零
        memset( class_total, 0, sizeof(class_total) );  // 各科成绩清零
        memset( student, 0, sizeof(student) );          // 学生成绩清零


        for(i=0;i<n;i++)                    // 一共有 i 名学生
        {
            for( j=0; j<m; j++ )            // 每名学生有 j 个科目的分数
            {
                scanf( "%lf", &student[i][j] );    // 读取 i 学生的 j 科数据
                
                s += student[i][j];               // 将 i 学生的 j 科成绩计算到总成绩
                class_total[j] += student[i][j];  // 将 j 科成绩计算到总分数
                student[i][5] += student[i][j];         // 计算平均成绩
            }
            student[i][5] = student[i][5] / m;           // 计算 i 学生的平均成绩, 放入到 student[i][5] 中
        }


        // 输出的第一行包含n个数据，表示n个学生的平均成绩
        for( i = 0; i < n; i++ )            // 同样的, i 代表当前是哪位学生
        {
            if(i != 0) printf(" ");
            printf( "%.2f", student[i][5] );     // 输出 i 学生的平均成绩, 大概 55 行, student[i][5] 所存的是对应学生的个人平均
        }



        // 输出的第二行包m个数据，表示m门课的平均成绩，结果保留两位小数
        putchar( '\n' );                    // 换行
        for( i = 0; i < m; i++ )            // 有变化, i 代表当前是哪门科目
        {
            if(i != 0) printf(" ");
            printf( "%.2f", ( class_total[i] / n ) );          // 科目总分 / 学生数 == 科目平均分
        }


        // 输出的第三行是一个整数，表示该班级中  各科  成绩均大于等于平均成绩的学生数量。每个测试实例后面跟一个空行。
        putchar( '\n' );                    // 换行
        int cnt = 0, mc;
        for (i = 0; i < n; i++) {
            mc = 0;
            for (j = 0; j < m; j++) {
                if (student[i][j] < class_total[j] / n ) break;
                else mc++;
            }
            if (mc == m) cnt++;
        }
        printf( "%d\n\n", cnt );
    }
}