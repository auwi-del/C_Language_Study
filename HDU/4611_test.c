#include <stdio.h>
#include <math.h>

int main()
{
    int pa, pb, N, A, B, i, j, score;
    while(1)
    {
        pa = pb = 0;
        scanf( "%d %d %d", &N, &A, &B );
        for ( i = 0; i < N; i++ )
        {
            if( pa > A )
            {
                pa -= A;
                printf( "\n" );
            }
                
            if( pb > B )
                pb -= B;
            
            score += abs( pa - pb );
            printf( "%d\t", abs( pa - pb ) );

            pa++;
            pb++;
        }
    }
}