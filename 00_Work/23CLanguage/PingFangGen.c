#include <stdio.h>
#include <math.h>

int main() {
   double a, b, c;
   printf("������ϵ�� a, b, c:");
   scanf("%lf %lf %lf", &a, &b, &c);
   
   double discriminant = pow(b, 2) - 4 * a * c;



   if (discriminant == 0) {
       double x1 = -b / (2 * a);
       printf("������������ͬ�ĸ�,������λС��:%lf %lf\n", x1, x1);
   } 

   else if (discriminant > 0) {
       double x1 = (-b + sqrt(discriminant)) / (2 * a);
       double x2 = (-b - sqrt(discriminant)) / (2 * a);
       printf("������������ͬ�ĸ�,������λС��:%lf %lf\n", x1, x2 );
   } 
   
   
   else {
       if (a == 0) {
           printf("������������,��Ϊ a=0\n");
       } else {
           printf("������ʵ��\n");
       }
   }
   system( "pause" );
   return 0;
}