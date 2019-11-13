#include <stdio.h>
#include <stdlib.h>
#include <string.h>             
double calculate(double a, double b, int flag1)
{
    if (flag1 == 1)
        return a + b;
    if (flag1 == 2)
        return a - b;
    if (flag1 == 3)
        return a * b;
    if (flag1 == 4)
        return a / b;
}
int main()
{
    double a[50], sum2 = 0, sum1 = 0, sum[50], end1;
    int i, j, z = 0, flag = 0, flag1 = 0,flag2=0, m, n, q, d = 0,record=0; //flag判断有无等号赋值
    char input[1000], b[50][200], str[200];               //变量名存于b
    while (scanf("%s", input) != EOF)
    {
        /*          */
        if (strcmp(input, "exit") == 0)
            break;
        /*          */
        flag = 0,flag1=0,flag2=0;
        j = 0,d=0;
        z=record;
        for(i=0;i<50;i++)
            sum[i]=0;
        /* ********开始取变量*********** */
        for (i = 0; i < strlen(input); i++) //取变量
        {
            if (input[i] == 61)
            {
                flag = 1;
                j = i;
            }
            if (flag == 1)
            {
                for(i=0;i<z;i++)
                    if(strcmp(b[i],b[z])==0)
                    {
                        flag2=1;
                        break;
                    }
                if(flag2==0)
                {
                    strncpy(b[z], input, j);            //处理无重复情况
                    b[z][j] = '\0';
                    z++;
                    record=z;
                    break;
                }
                else                                    //处理重复情况
                {
                    z=i;
                    break;
                }
                
            }
        } //取变量完成       //j处为 = 所在点
        /* **********开始进行数据处理************ */
        if(flag==0)
        {
            j=-1;
            z=50;
        }
            
        for (i = j + 1; i < strlen(input); i++)
        {
            
            sum2 = 0, sum1 = 0;
            if(i==j+1)
            {
                if (input[i] >= 48 && input[i] <= 57) //数字处理
                {
                    for (m = i; m < strlen(input); m++)
                    {
                        if (input[m] >= 48 && input[m] <= 57)
                            sum2 = sum2 * 10 + (input[m] - 48);
                        if (input[m]=='.')
                        {
                            for (n = m + 1; n < strlen(input); n++)
                                if (input[n] > 57 || input[n] < 48)
                                    break;
                            for (q = n - 1; q > m; q--)
                                sum1 = sum1 / 10 + ((double)(input[q] - 48))/10;
                            i = n-1;
                            break; //处理小数
                        }
                        if ((input[m] == '+' || input[m] == '-' || input[m] == '*' || input[m] == '/'))
                        {
                            i = m-1;
                            break;
                        }
                    }
                    sum[d++] = sum2 + sum1;
                }
                else if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) //字母处理行 变量开头需符合c语言命名规则
                {
                    for (m = i + 1; m < strlen(input); m++)
                        if (input[m] == '+' || input[m] == '-' || input[m] == '*' || input[m] == '/')
                            break;
                    strncpy(str, input + i, m - i);
                    str[m - i] = '\0';
                    for (n = 0; n < z; n++)
                    {
                        if (strcmp(b[n], str) == 0)
                            sum[d++] = a[n];
                    }
                    i = m-1;
                }
                a[z - 1] = sum[d-1];           //运算变量值
            }
            /*     ************************************         四则运算处理行*/
            if (input[i] == '+')
                flag1 = 1;
            if (input[i] == '-')
                flag1 = 2;
            if (input[i] == '*')
                flag1 = 3;
            if (input[i] == '/')
                flag1 = 4;
            sum2 = 0, sum1 = 0;
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            {
                i++;
                if (input[i] >= 48 && input[i] <= 57) //数字处理
                {
                    for (m = i; m < strlen(input); m++)
                    {
                        if (input[m] >= 48 && input[m] <= 57)
                            sum2 = sum2 * 10 + (input[m] - 48);
                        if (input[m]=='.')
                        {
                            for (n = m + 1; n < strlen(input); n++)
                                if (input[n] > 57 || input[n] < 48)
                                    break;
                            for (q = n - 1; q > m; q--)
                                sum1 = sum1 / 10 + ((double)(input[q] - 48))/10;
                            i = n-1;
                            break; //处理小数
                        }
                        if ((input[m] == '+' || input[m] == '-' || input[m] == '*' || input[m] == '/'))
                        {
                            i = m-1;
                            break;
                        }
                    }
                    sum[d++] = sum2 + sum1;
                }
                else if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) //字母处理行 变量开头需符合c语言命名规则
                {
                    for (m = i + 1; m < strlen(input); m++)
                        if (input[m] == '+' || input[m] == '-' || input[m] == '*' || input[m] == '/')
                            break;
                    strncpy(str, input + i, m - i);
                    str[m - i] = '\0';
                    for (n = 0; n < z; n++)
                    {
                        if (strcmp(b[n], str) == 0)
                            sum[d++] = a[n];
                    }
                    i = m-1;
                }
                a[z - 1] = calculate(a[z - 1], sum[d-1], flag1);           //运算变量值
            }
        }
        /*赋值部分处理完毕*/
        if(flag==0)
            printf("%lf\n",a[49]);
    }
    return 0;
}