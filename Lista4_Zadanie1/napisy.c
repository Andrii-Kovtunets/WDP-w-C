#include "napisy.h"

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
