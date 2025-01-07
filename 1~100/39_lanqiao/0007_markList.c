#include <stdio.h>
    
int main () 
{
    int hh, mm, ss;
    
    //input time
    printf("Enter time in HH:MM:SS format: ");
    scanf("%d:%d:%d", &hh, &mm, &ss) ;
    //print 
    printf("Time is: hours %d, minutes %d and seconds %d\n" ,hh, mm, ss) ;
    
    return 0;
}