#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int GetValueOfBit(unsigned int number, int numberOfBit);
void NegativeNumber(int *number, int numberOfBit);
void PrintNumberInBitForm(unsigned int number);

int main()
{
    unsigned int number;
    printf("Please enter number > ");
    scanf("%d", &number);

    PrintNumberInBitForm(number);

    int numberOfBit;
    printf("\nPlease enter number of bit > ");
    scanf("%d", &numberOfBit);

    printf("\nBit with number %d = %d\n", numberOfBit, GetValueOfBit(number, numberOfBit));

    NegativeNumber(&number, numberOfBit);

    printf("\nNumber = %d\n", number);
    PrintNumberInBitForm(number);
    printf("\n");

    int countOfOnBits = 0;
    bool FirstPositionFinded = false;
    int positionOfFirstOnBit;
    int positionOfLastOnBit;
    for(int i = 31; i >= 0; i--)
    {
        if(GetValueOfBit(number, i))
        {
            if(!FirstPositionFinded)
            {
                positionOfFirstOnBit = i;
                FirstPositionFinded = true;
            }
            positionOfLastOnBit = i;
            countOfOnBits++;
        }
    }
    printf("Count of \"On\" bits = %d\n\n", countOfOnBits);

    if(countOfOnBits > 0)
    {
        printf("Position of first 1 = %d\n", positionOfFirstOnBit);
        printf("Position of last 1 = %d\n", positionOfLastOnBit);
    }
    else
    {
        printf("This number does not include 1, because it is 0\n");
    }

    printf("\nNumber in 2 form = ");
    for(int i = positionOfFirstOnBit; i >= 0; i--)
    {
        /*if(i % 4 == 0)
        {
            printf("%d ", GetValueOfBit(number, i));
        }
        else
        {*/
            printf("%d", GetValueOfBit(number, i));
        //}
    }
    printf("\n\n\n\n");
}

int GetValueOfBit(unsigned int number, int numberOfBit)
{
    /*int mask1 = 00000001;
    int mask2 = 00000010;
    int mask3 = 00000100;
    int mask4 = 00001000;
    int mask5 = 00010000;
    int mask6 = 00100000;
    int mask7 = 01000000;
    int mask8 = 10000000;*/

    int mask = 1 << numberOfBit;

    return ((number & mask) == mask);
}

void NegativeNumber(int *number, int numberOfBit)
{
    int mask = 1 << numberOfBit;
    if(GetValueOfBit(*number, numberOfBit))
    {

        *number = *number & ~mask;
    }
    else
    {
        *number = *number | mask;
    }
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
