#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
long long power(long long a, long long n){
    long long ans=1;
    while(n){
         if(n%2==1) ans*=a;  
         a*=a;
         a%=1000;
         n>>=1;
         if(ans/1000>=1)
            ans=ans%1000;
     }
     return ans;
}

int main(){
    int a,b,c,i,j;
    
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a==0&&b==0)
            break;
        printf("%lld\n",power(a,b)%1000);
        
    }
    return 0;
}