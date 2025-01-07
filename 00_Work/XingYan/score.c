#include <stdio.h>

int main()
{
    int score;
    printf( "«Î ‰»Îƒ„µƒ≥…º®" );
    scanf( "%d", &score );
    score = score / 10;

    switch ( score )
    {
        case 1: case 2: case 3: case 4: case 5: case 6: 
            printf( "D\n" );
            break;
        case 7: 
            printf( "C\n" );
            break;
        case 8: 
            printf( "B\n" );
            break;
        case 9:
            printf( "A\n" );
            break;
    }
    system( "pause" );
}