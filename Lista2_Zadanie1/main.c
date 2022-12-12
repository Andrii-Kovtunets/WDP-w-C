#include <stdio.h>
#include <stdlib.h>

//#define Print

int main(int argc, char* argv[])
{
    char* T = argv[1];
    int length = 0;
    for(int i = 0; T[i] != '\0'; i++)
    {
        printf("%c", T[i]);
        length++;
    }
    printf("\n");

    printf("Length = %d\n", length);

    int N;
    scanf("%d", &N);

#ifdef Print
    printf("Users input: %d\n", N);
#endif

    int B;

#ifdef Print
    printf("B = ");
#endif

    int k = 0;
    for(int i = 0; i < length; i++)
    {
        B = T[i] - '0';

#ifdef Print
        printf("%d", B);
#endif

        k = (k * 10 + B) % N;

#ifdef Print
        printf("k = %d\n", k);
#endif
    }

    printf("\nResult: ");
    if(k == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
