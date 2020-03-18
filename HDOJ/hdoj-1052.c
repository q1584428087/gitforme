#include<stdio.h>
//http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=35996&messageid=2&deep=1
int main()
{
	int n,i,j,sum,temp,k,z,m,lefttian,leftking,righttian,rightking;
	int a[2][1001];
	while(scanf("%d",&n) != EOF && n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[0][i]);
		for(i=0;i<n;i++)
			scanf("%d",&a[1][i]);
		j=0,k=0,z=0,m=0;
		for(i=0;i<n-1;i++)
		{
			for(j=n-1;j>i;j--)
			{
				if(a[0][j]>a[0][j-1])
				{
					temp=a[0][j];
					a[0][j]=a[0][j-1];
					a[0][j-1]=temp;
				}
			}
			for(j=n-1;j>i;j--)
			{
				if(a[1][j]>a[1][j-1])
				{
					temp=a[1][j];
					a[1][j]=a[1][j-1];
					a[1][j-1]=temp;
				}
			}
		}
		leftking=0;
		lefttian=0;
		righttian=n-1;
		rightking=n-1;
		while (lefttian<=righttian)
		{
			if(a[0][lefttian]>a[1][leftking])
			{
				k++;
				leftking++;
				lefttian++;
			}
			else if (a[0][lefttian]>a[1][leftking])
			{
				k--;
				righttian--;
				leftking++;
			}
			else
			{
				 if (a[0][righttian] > a[1][rightking])
                {
                    k++;
                    righttian--;
                    rightking--;
                }
                else
                {
                    if (a[0][righttian] < a[1][leftking])
                        k--;
                    righttian--;
                    leftking++;
                }
			}
		}
		
		printf("%d\n",k*200);
	}
	
	return 0;
}