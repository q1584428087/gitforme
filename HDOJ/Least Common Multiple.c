#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
long long gcd(long a,long b){
    int ans=0,temp;
    while(a!=0&&b!=0){
        ans=a%b;
        a=b;
        b=ans;
    }
    return max(a,b);
}
int main()
{
    long long a,b,n=0,N=0,t=0;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);




        a=1,b=0;                                //核心 最小公倍数
        for(int i=0;i<n;i++)
        {
            
            scanf("%d",&b);
            a=a*b/gcd(a,b);
        }
        printf("%d\n",a);


        
    }
    return 0;
}