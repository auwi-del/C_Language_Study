#include <stdio.h>

int main()
{
    int a, b;
    while( scanf( "%d %d", &a, &b ) != EOF )
    {
        if( a == b )
            printf( "YES\n" );
        else
            printf( "NO\n" );
    }
}