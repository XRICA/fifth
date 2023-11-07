#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ERRLOG(errmsg)                                          \
    do                                                          \
    {                                                           \
        perror(errmsg);                                         \
        printf("%s - %s - %d\n", __FILE__, __func__, __LINE__); \
        exit(1);                                                \
    } while (0)

void cal(const char *argv,int begin,int len,long *sum)
{
    for (int j = begin; j < len; j++)
    {
        char arg = argv[j];
        if (arg >= '0' && arg <= '9')
        {
            *sum += pow(16,len-j-1)*(int)(arg-48);
        }
        else if (arg >= 'A' && arg <= 'F')
        {
            *sum += pow(16,len-j-1)*(int)(arg-55);
        }
        else if (arg >= 'a' && arg <= 'f')
        {
            *sum += pow(16,len-j-1)*(int)(arg-87);
        }
        else
        {
            printf("%c is out of range\n", argv[j]);
            return;
        }
    }
}

    int main(int argc, const char *argv[])
    {
        long sum = 0;
        for (int i = 1; i < argc; i++)
        {
            int len = strlen(argv[i]);
             if (len == 1 || len >=2 && argv[i][1] != 'x')
            {
                cal(argv[i],0,len,&sum);
            }
            else if (len >= 3 && argv[i][1] == 'x')
            {
                cal(argv[i],2,len,&sum);
            }
        }
        if (sum >= 0)
        {
            printf("%ld", sum);
        }
        printf("\n");
    }