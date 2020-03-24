#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int C,N,M,i,j,a[101][101];
    scanf("%d",&C);
    while (C--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=N-1;i>0;i--)
        {
            for(j=0;j<i+1;j++)
                a[i-1][j]=a[i-1][j]+(a[i][j]>a[i][j+1]?a[i][j]:a[i][j+1]);
        }
        printf("%d\n",a[0][0]);
    }
    
    return 0;
}
