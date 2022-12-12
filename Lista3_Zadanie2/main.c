#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long d;
    printf("Please write d > ");
    scanf("%lld", &d);
    int k;
    printf("Please write k(from 2 to 36) > ");
    scanf("%d", &k);

    if(k < 11)
    {
        int power = 1;
        long long sum = 0;

        //printf("\n");

        int n;
        while(d > 0)
        {
            n = d / k;
            sum += (d - n * k) * power;
            d = n;

            //printf("d = %d\n", d);

            power *= 10;

            //printf("Sum = %d\n", sum);
        }

        printf("\nResult: %d", sum);
    }
    else
    {
        //printf("\nWe are here\n");

        char number[1000];
        int index = 0;
        int n;
        while(d > k)
        {
            n = d / k;
            if(n < 10)
            {
                number[index] = 48 + n;
            }
            else
            {
                number[index] = 55 + n;
            }

            d = d - k * n;

            //printf("D = %d\n", d);

            index++;
        }

        if(d < 10)
        {
            number[index] = 48 + d;
        }
        else
        {
            //printf("\nWe are here\n");

            number[index] = 55 + d;
        }
        index++;
        number[index] = '\0';

        printf("\nResult: %s", number);
    }
}
