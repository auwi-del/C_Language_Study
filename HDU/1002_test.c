#include <stdio.h>
int main()
{
    int i;
    for ( i = 0; i < 200; i++ )
    {
        printf( "%d == %c\n", i, i );
    }
    system( "pause" );
}