#include <stdio.h>

int main()
{
	int i, ans, input;
	while( scanf( "%d", &input ) != EOF )
	{
		ans = 0;
		for( i = 0; i <= input; i++ )
			ans += i;
		printf( "%d\n", ans);
	}
}
