#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct Student
{
    int number;
    double score[5];
    double sum;
    double average;
}stu[11];

int main()
{
    int i,j,k,n;
    double average1[5],temp;
    struct Student *p=stu;
    for(i=0;i<10;i++)
    {
        printf("number is XX,score=XX XX XX XX XX\n");
        scanf("%d %lf %lf %lf %lf %lf",
        &stu[i].number,
        &((p+i)->score[0]),
        &((p+i)->score[1]),
        &((p+i)->score[2]),
        &((p+i)->score[3]),
        &((p+i)->score[4]));
        for(j=0;j<5;j++)
            (p+i)->sum+=(p+i)->score[j];
        (p+i)->average=(p+i)->sum/5.;
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<10;j++)
            average1[i]+=(p+j)->score[i];
    }

    for(i=0;i<9;i++)
    {
        for(j=9;j>i;j--)
        {
            if((p+j)->average<(p+j-1)->average)
            {
                stu[10]=stu[j];
                stu[j]=stu[j-1];
                stu[j-1]=stu[10];
            }
        }
    }
    printf("\n\n\n");
    for(i=0;i<10;i++)
    {
        printf("number is %8d   score1 is %7.3lf   score2 is %7.3lf   score3 is %7.3lf   score4 is %7.3lf   score5 is %7.3lf   (sum is %7.3lf  || average is %7.3lf)\n\n\n",
        (p+i)->number,
        (p+i)->score[0],
        (p+i)->score[1],
        (p+i)->score[2],
        (p+i)->score[3],
        (p+i)->score[4],
        (p+i)->sum,
        (p+i)->average);

    }
        
    return 0;
}
