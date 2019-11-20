#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int N,i,j,ballon[1000],flag=0,n=0,max=0,p=0;
    char str[1000][15],str1[15];
    while (scanf("%d",&N)!=EOF)
    {
        if(N==0)
            break;
        n=-1,max=0,p=0;
        for(i=0;i<N;i++)
        {
            flag=0;
            scanf("%s",str1);
            for(j=0;j<=n;j++)
            {
                if(strcmp(str[j],str1)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                ballon[j]++;
            else if(flag==0)
            {
                ballon[j]=1;
                strcpy(str[j],str1);
                n++;
            }
        }
        for(i=0;i<=n;i++)
        {
            if(max<ballon[i])
            {
                p=i;
                max=ballon[i];
            }
        }
        printf("%s\n",str[p]);
            
    }
    return 0;
}
