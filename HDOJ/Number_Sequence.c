#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int A,B,f1,f2,f,i=0;
    long long n;
    while (scanf("%d %d %lld",&A,&B,&n) != EOF)
    {
        f1=1,f2=1,f=1;
        if(n%48==0)
            f=0;
        n=n%48;
        if (A == 0 && B == 0 && n == 0)
            break;
        for(i=3;i<=n;i++)
        {
            f=(A*f2+B*f1) % 7;
            f1=f2;
            f2=f;
        }
        printf("%d\n", f);
    }
    return 0;
}
