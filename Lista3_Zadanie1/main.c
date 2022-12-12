#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    printf("Enter count of lines > ");

    while(scanf("%d", &n) == 0)
    {
        printf("\nSorry, your input was bad. Please try again: \n\n");
        printf("Enter count of lines > ");
        while(getchar()!='\n');
    }

    while(n < 1 || n > 20)
    {
        printf("\nSorry, you can not choose numbers less tha 1 or bigger than 20\n\nPlease try again: \n");
        printf("Enter count of lines > ");

        while(scanf("%d", &n) == 0)
        {
            printf("\nSorry, your input was bad. Please try again: \n\n");
            printf("Enter count of lines > ");
            while(getchar()!='\n');
        }
    }

    printf("\nResult: \n\n");

    int countOfSpacesAtTheBeginOfTheLine = 0;
    int countOfSpacesInTheMiddleOfTheLine = n * 2 - 3;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < countOfSpacesAtTheBeginOfTheLine; j++)
        {
            printf(" ");
        }
        printf("*");
        for(int j = 0; j < countOfSpacesInTheMiddleOfTheLine; j++)
        {
            printf(" ");
        }
        printf("*\n");

        countOfSpacesAtTheBeginOfTheLine++;
        countOfSpacesInTheMiddleOfTheLine-=2;
    }
    for(int i = 0; i < countOfSpacesAtTheBeginOfTheLine; i++)
    {
        printf(" ");
    }
    printf("*");
}
