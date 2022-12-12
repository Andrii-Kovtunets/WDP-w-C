#include <stdio.h>
#include <stdlib.h>

int GetValueOfBit(unsigned int number, int numberOfBit);
void PrintNumberInBitForm(unsigned int number);

int main()
{
    int n;
    printf("Please enter n > ");
    scanf("%d", &n);

    PrintNumberInBitForm(n);
    printf("\n");

    int s;
    printf("Please enter s > ");
    scanf("%d", &s);
    s = s % 32;

    if(s > 0)
    {
        for(int i = 0; i < s; i++)
        {
            n = n << 1;
        }
    }
    else if(s < 0)
    {
        /////
        /*n = (n >> -s) ^ (n << 32 + s);
        PrintNumberInBitForm(n);*/
        /////

        int a = n;
        for(int i = 0; i < -s; i++)
        {
            a = a >> 1;
        }

        for(int i = 0; i < 32 + s; i++)
        {
            n = n << 1;
        }

        n = n ^ a;
    }

    PrintNumberInBitForm(n);
}

int GetValueOfBit(unsigned int number, int numberOfBit)
{
    int mask = 1 << numberOfBit;

    return ((number & mask) == mask);
}

void PrintNumberInBitForm(unsigned int number)
{
    int valueOfBit;
    printf("Number in bit form = ");
    for(int i = 31; i >= 0; i--)
    {
        valueOfBit = GetValueOfBit(number, i);
        if(i % 4 == 0)
        {
            printf("%d ", valueOfBit);
        }
        else
        {
            printf("%d", valueOfBit);
        }
    }
    printf("\n");
}
