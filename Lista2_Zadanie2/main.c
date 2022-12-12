#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10000

//#define Print

int main()
{
    char row[MAX_LENGTH];
    printf("Your enter > ");

    //
    int ch;
    ch = getchar();
    char c = ch;
    int length = 0;
    for(int i = 0; /*ch != EOF &&*/ (ch != '\n'); i++, length++)
    {
        row[i] = ch;
        printf("%c", row[i]);
        ch = getchar();
    }
    printf("\nLength = %d\n", length);

    for(int i = 0; i < length; i++)
    {
        if(row[i] < 32 || row[i] > 126)
        {
            /*for(int j = i; j < length - 1; j++)
            {
                row[j] = row[j + 1];
            }*/
        }
        if(row[i] == 9)
        {
            row[i] = 32;
        }
    }

    printf("Final line: ");
    for(int i = 0; i <= length; i++)
    {
        putchar(row[i]);
    }

    //

    /*gets(row);
    printf("Users input: %s\n", row);

    int Length = 0;
    for(int i = 0; row[i] != '\0'; i++)
    {
        Length++;
    }
    printf("Length = %d", Length);

#ifdef Print
    printf("Users input: %s", row);
#endif
*/
}
