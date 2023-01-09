#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    short rok;
    short miesiac;
    short dzien;
}kalendarz;

bool mniejszy(kalendarz* k1, kalendarz* k2);
void Sort(kalendarz** array, int length);

char** split(const char[]);
int GetLength(const char line[]);
int GetCountOfSpaces(const char line[], int length);
int* GetLengthesOfWords(const char line[], int lengthOfLine, int countOfSpaces);

int main()
{
    int length;
    printf("Please write number n > ");
    scanf("%d", &length);
    kalendarz** array = (kalendarz**)calloc(length, sizeof(kalendarz*));

    while (getchar() != '\n'){}
    for(int i = 0; i < length; i++)
    {
        char* line = (char*)calloc(1024, sizeof(char));
        printf("Please write date > ");
        gets(line);

        char** data = split(line);
        kalendarz k = {atoi(data[2]), atoi(data[1]), atoi(data[0])};
        array[i] = malloc(sizeof(kalendarz));
        *array[i] = k;

        free(line);
        for(int j = 0; j < 3; j++)
        {
            free(data[j]);
        }
        free(data);
    }

    Sort(array, length);

    printf("\n");
    printf("Sorted: \n\n");
    for(int i = 0; i < length; i++)
    {
        printf("%02d/%02d/%02d\n", array[i][0].dzien, array[i][0].miesiac, array[i][0].rok);
        free(array[i]);
    }
    free(array);

    return 0;
}

int* GetLengthesOfWords(const char line[], int lengthOfLine, int countOfSpaces)
{
    int* lengthesOfWords = (int* )calloc(countOfSpaces + 1, sizeof(int*));

    for (int i = 0, index = 0; i < lengthOfLine; i++)
    {
        if (!isspace(line[i]))
        {
            lengthesOfWords[index]++;
        }
        else
        {
            lengthesOfWords[index]++;
            index++;
        }
    }

    return lengthesOfWords;
}

char** split(const char line[])
{
    int length = GetLength(line);
    int countOfSpaces = GetCountOfSpaces(line, length);
    int countOfWords = countOfSpaces + 1;
    int* lengthesOfWords = GetLengthesOfWords(line, length, countOfSpaces);

    char** words = (char**)calloc(countOfWords + 1, sizeof(char**));
    for (int i = 0, indexInLine = 0; i < countOfWords; i++)
    {
        words[i] = (char*)calloc(lengthesOfWords[i], 1);
        for (int j = 0; j < lengthesOfWords[i] - 1; j++)
        {
            //copy letters from line to our word
            words[i][j] = line[indexInLine];
            //Moving in line
            indexInLine++;
        }
        //Adds symbol of end of the line in our word
        words[i][lengthesOfWords[i] - 1] = '\0';
        //Miss spaces
        indexInLine++;
    }

    free(lengthesOfWords);

    return words;
}

int GetCountOfSpaces(const char line[], int length)
{
    int countOfSpaces = 0;
    for (int i = 0; i < length; i++)
    {
        if (isspace(line[i]))
        {
            countOfSpaces++;
        }
    }

    return countOfSpaces;
}

int GetLength(const char line[])
{
    int length = 0;
    while (line[length] != '\0')
    {
        length++;
    }
    length++;

    return length;
}

void Sort(kalendarz** array, int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(mniejszy(array[j], array[i]))
            {
                kalendarz* temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

bool mniejszy(kalendarz* k1, kalendarz* k2)
{
    if(k1->rok < k2->rok)
    {
        return true;
    }
    else if(k1->rok == k2->rok)
    {
        if(k1->miesiac < k2->miesiac)
        {
            return true;
        }
        else if(k1->miesiac == k2->miesiac)
        {
            if(k1->dzien < k2->dzien)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
