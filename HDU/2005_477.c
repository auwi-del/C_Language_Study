/* Note:Your choice is C IDE */
#include <stdio.h>
int main()
{
	int y,m,d,s;
  while(scanf("%d/%d/%d",&y,&m,&d)!=EOF)
  {
  	if((y%4==0&&y%100!=0)||(y%400==0))
  	{
  		switch(m)
  		{
  			case 1:s=d;break;
  			case 2:s=31+d;break;
  			case 3:s=31+29+d;break;
  			case 4:s=31+29+31+d;break;
  			case 5:s=31+29+31+30+d;break;
  			case 6:s=31+29+31+30+31+d;break;
  			case 7:s=31+29+31+30+31+30+d;break;
  			case 8:s=31+29+31+30+31+30+31+d;break;
  			case 9:s=31+29+31+30+31+30+31+31+d;break;
  			case 10:s=31+29+31+30+31+30+31+31+30+d;break;
  			case 11:s=31+29+31+30+31+30+31+31+30+31+d;break;
  			case 12:s=31+29+31+30+31+30+31+31+30+31+30+d;break;
  		}
  		}
  		
  	
  	if(!(y%4==0&&y%100!=0)||(y%400==0))
  	{
  	switch(m)
  		{
  			case 1:s=d;break;
  			case 2:s=31+d;break;
  			case 3:s=31+28+d;break;
  			case 4:s=31+28+31+d;break;
  			case 5:s=31+28+31+30+d;break;
  			case 6:s=31+28+31+30+31+d;break;
  			case 7:s=31+28+31+30+31+30+d;break;
  			case 8:s=31+28+31+30+31+30+31+d;break;
  			case 9:s=31+28+31+30+31+30+31+31+d;break;
  			case 10:s=31+28+31+30+31+30+31+31+30+d;break;
  			case 11:s=31+28+31+30+31+30+31+31+30+31+d;break;
  			case 12:s=31+28+31+30+31+30+31+31+30+31+30+d;break;
  	}
  	
  	}
  	printf("%d\n",s);
  	s=0;
  }
  return 0;
  
}