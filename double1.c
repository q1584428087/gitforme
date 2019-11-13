#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int judge(int a,int b,int p)
{
    if(a+b+p>=10)
        return 1;
    else
        return 0;
    return 0;
}
int max1(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int i,j,n,z,p,flag=0;
    char a1[1000],b1[1000],a[1000],b[1000],end1[1001];
    int a2[1001],b2[1001],end[1001];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        p=0;
        scanf("%s",a1);
        scanf("%s",b1);
        for(j=0;j<1001;j++)
        {
            a2[j]=0;
            b2[j]=0;
        }
        for(j=0;j<strlen(a1);j++)
        {
            a[j]=a1[strlen(a1)-j-1];
        }
        a[j]='\0';
        for(j=0;j<strlen(b1);j++)
            b[j]=b1[strlen(b1)-j-1];
        b[j]='\0';
        for(j=0;j<strlen(a);j++)
            a2[j]=a[j]-48;
        for(j=0;j<strlen(b);j++)
            b2[j]=b[j]-48;

        for(j=0;j<max1(strlen(a),strlen(b));j++)
        {
            if(judge(a2[j],b2[j],p)==1)
            {
                end[j]=a2[j]+b2[j]+p-10;
            }
            else
            {
                end[j]=a2[j]+b2[j]+p;
            }
            p=judge(a2[j],b2[j],p);
        }
        if(p==1)
            end[j]=1;
        for(z=j;z>=0;z--)
            end1[j-z]=end[z]+48;
        if(p==0)
        {
            for(z=0;z<j;z++)
            {
                end1[z]=end1[z+1];
            }
            end1[j]='\0';
        }
        if(i!=1)
        {
            printf("\n");
        }
        printf("Case %d:\n",i);
        printf("%s + %s = %s\n",a1,b1,end1);

    }
    return 0;
}
