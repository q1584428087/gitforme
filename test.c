#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,temp,max,m,i,j,z,sum=0,l=0,ti[1000],si[1000];
	scanf("%d",&n);
	m=0;
	for(i=0,sum=0;i<n;i++)
	{
		scanf("%d %d",&ti[i],&si[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;j--)
		{
			if(si[j]>si[j-1])
			{
				temp=si[j-1];
				si[j-1]=si[j];
				si[j]=temp;
				temp=ti[j-1];
				ti[j-1]=ti[j];
				ti[j]=temp;
			}
		}
	}
	l=n-1;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",ti[i],si[i]);
	}
	printf("\n");
	for(i=n-1;i>=0;i--)
	{
		for(j=0;j<l;j++)
		{
			if(ti[j]>=i+1)
			{
				temp=si[j];
				for(z=j;z<i;z++)
				{
					si[z]=si[z+1];
				}
				si[i]=temp;

				temp=ti[j];
				for(z=j;z<i;z++)
					ti[z]=ti[z+1];
				ti[i]=temp;
				
				l=i;
				break;
			}
		}
		printf("************\n");
		for(j=0;j<n;j++)
		{
			printf("%d %d\n",ti[j],si[j]);
		}
		printf("************\n");
	}
	for(i=0;i<n;i++)
	{
		if(ti[i]<i+1&&ti[i]<=m)
			continue;
		printf("%d %d\n",ti[i],si[i]);
		sum+=si[i];
		m++;
	}
	printf("\n");
	printf("%d\n",sum);
	return 0;
}