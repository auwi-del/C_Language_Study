#include <stdio.h>

int main()
{
    int len, i, j, zeroNum;
    int arr[40] = {};
    zeroNum = 0;
    scanf("%d", &len);

    for(i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(j = 0; j < len; j++)
    {
        if(arr[j] == 0)
        {
            zeroNum++;
            continue;
        }
        printf("%d ", arr[j]);
    }

    printf("\n%d", zeroNum);
    return 0;
}