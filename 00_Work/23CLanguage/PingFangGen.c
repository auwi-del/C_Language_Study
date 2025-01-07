#include <stdio.h>
#include <math.h>

int main() {
   double a, b, c;
   printf("请输入系数 a, b, c:");
   scanf("%lf %lf %lf", &a, &b, &c);
   
   double discriminant = pow(b, 2) - 4 * a * c;



   if (discriminant == 0) {
       double x1 = -b / (2 * a);
       printf("方程有两个相同的根,保留两位小数:%lf %lf\n", x1, x1);
   } 

   else if (discriminant > 0) {
       double x1 = (-b + sqrt(discriminant)) / (2 * a);
       double x2 = (-b - sqrt(discriminant)) / (2 * a);
       printf("方程有两个不同的根,保留两位小数:%lf %lf\n", x1, x2 );
   } 
   
   
   else {
       if (a == 0) {
           printf("方程有无穷多解,因为 a=0\n");
       } else {
           printf("方程无实根\n");
       }
   }
   system( "pause" );
   return 0;
}