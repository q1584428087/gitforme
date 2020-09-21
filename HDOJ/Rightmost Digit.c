#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long power(long long a, long long n){
    long long ans=1;
    while(n){
         if(n%2==1) ans*=a;  
         a*=a;
         a%=10;
         n>>=1;
         if(ans/10>=1)
            ans=ans%10;
     }
     return ans;
}

int main(){
    int a,b,c,i,j;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&a);
        printf("%lld\n",power(a,a)%10);
        
    }
    return 0;
}