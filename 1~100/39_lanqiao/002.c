#include <stdio.h>

int main()
{
  int i=0, num = 0, n = 0; 
  int jige = 0, youxiu = 0;
  int jigelv, youxiulv;

  scanf("%d", &n);              //获取输入: 考试人数

  for(i = 0; i < n; i++)
  {
    scanf("%d", &num);
    if(num >= 60)
      jige++;
    if(num >= 85)
      youxiu++;
  }
    
    jigelv   = (int) ((((float)jige   / (float)n) * 100) + 0.5);
    youxiulv = (int) ((((float)youxiu / (float)n) * 100) + 0.5);

  printf("%d%%\n", jigelv);
  printf("%d%%\n", youxiulv);
  return 0;
}




// 0 1 2 3 4 5 6 7 

// 2 0 2 0 0 2 0 2