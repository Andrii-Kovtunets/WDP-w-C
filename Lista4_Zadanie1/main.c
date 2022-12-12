#include <stdio.h>
#include <stdlib.h>

//#include "napisy.h"

int GetLength(char* arr);
void Reverse_Array(char* arr);
void Copy(const char* arr, char* copy_arr);

void PrintArray(char* nameOfArray, char* arr);

int GetLength(char* array)
{
    int length = 0;
    while(array[length])
    {
        length++;
    }

    return length;
}

void Reverse_Array(char* array)
{
    int length = GetLength(array) - 1;
    char temp;
    for(int i = 0; i <= length / 2; i++)
    {
        temp = array[i];
        array[i] = array[length - i];
        array[length - i] = temp;
    }
}

void PrintArray(char* nameOfArray, char* array)
{
    printf("%s = %s\n", nameOfArray, array);
}

void Copy(const char* arr, char* copy_arr)
{
    int length = GetLength(arr);
    for(int i = 0; i <= length; i++)
    {
        copy_arr[i] = arr[i];
    }
}


int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; i++)
    {
        const char* t = argv[i];

        PrintArray("t", t);

        int length = GetLength(t);
        char arr[length + 1];
        //arr[length] = '\0';

        Copy(t, arr);
        PrintArray("arr", arr);

        Reverse_Array(arr);
        PrintArray("arr", arr);
        printf("\n\n");
    }

    return 0;
}
