#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int countDigits(int num)
{
    int res = 0, n = 0, j = 0;
    int tmp = num, tmp2 = num;
    while (tmp != 0)
    {
        tmp = tmp / 10;
        // printf("%d\n",n);
        n++;
    }
    for (j = 1; j <= n; j++)
    {
        if (j == 1 && (num % (num % 10) == 0))
        {
            res++;
        }
        else
        {
            tmp2 = tmp2 / 10;
            if (num % (tmp2 % 10) == 0)
            {
                res++;
            }
        }
    }
    return res;
}

int countDigits2(int num)
{
    int res = 0, n = 0, j = 1;
    int tmp = num, tmp2 = num;
    while (tmp2 != 0)
    {
        if (j)
        {
            if (num % (tmp2 % 10) == 0)
            {
                res++;
            }
            j = 0;
        }

        tmp2 = tmp2 / 10;
        if ((tmp2 != 0) && (num % (tmp2 % 10) == 0) )
        {
            res++;
        }
    }
    return res;
}

void printArray(int *a,int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
}


int punishmentNumber(int n){
    int i,j,res = 0;;
    int *arry;
    for ( i = 1; i <= n; i++)
    {
        int tmp = i*i;
        int tp = tmp,tp2 = tmp,len = 0;
        
        while(tp){
            tp /=10;
            len++;
        }
        arry = (int *)calloc(len,sizeof(int));
        for ( j = 0; j < len; j++)
        {
            if (j == 0)
            {
                arry[0] = tmp%10;
                continue;
            }
            tp2 /= 10;
            arry[j] = tp2%10;
        }

        for (int k = len-1; k >= 1 ; k--)
        {
            int sum = arry[k];
            for (int m = k-1; m >= 0 ; m--)
            {
                sum+=arry[m];
            }
            if (sum == i)
            {
                printf(" %d",i);
                res++;
            }



        }


        res++;
        // printArray(arry,len);
        
    }   
    
}

int main()
{
    punishmentNumber(10);    
}