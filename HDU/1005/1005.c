#include <stdio.h>
#include <string.h>

int a, b;

int fun( int n )
{
    if( n == 1 || n == 2 )
        return 1;
    
    return ( a * fun( n-1 ) + b * fun( n-2) ) % 7;
}

int main()
{
    int n;
    int i, j, k;

    while( 1 )
    {
        scanf( "%d %d %d", &a, &b, &n );
        if ( a == 0 )
            break;
        printf( "%d\n", fun( n ) );
        // if( i == n )
        // {
            
        // }
    }
}