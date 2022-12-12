#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct
{
    short godzina;
    short minuta;
    short sekunda;
}Zegar;

Zegar ustaw(short g, short m, short s);
bool sprawdz(Zegar zegar);
Zegar normuj(Zegar z);
void dodajgodziny(Zegar *z, short g);
void dodajminuty(Zegar *z, short m);
void dodajsekundy(Zegar *z, short s);
void drukuj(FILE *f, Zegar z);

const static Zegar poczatek = {0, 0, 0};

int main()
{
    Zegar zegar1 = {123, -76, 109};
    printf("Zegar1 = ");
    drukuj(stdout, zegar1);

    Zegar zegar2 = ustaw(zegar1.godzina, zegar1.minuta, zegar1.sekunda);
    printf("Zegar2 = ");
    drukuj(stdout, zegar2);

    Zegar zegar3 = normuj(zegar1);
    printf("Zegar3 = ");
    drukuj(stdout, zegar3);

    printf("\n");
    if(sprawdz(zegar2))
    {
        printf("Answer = Tak\n");
    }
    else
    {
        printf("Answer = Nie\n");
    }

    printf("\n");
    printf("Zegar 2:\n");

    dodajgodziny(&zegar2, 24);
    printf("Godzina: = ");
    drukuj(stdout, zegar2);

    dodajminuty(&zegar2, -40);
    printf("Minuta: = ");
    drukuj(stdout, zegar2);

    dodajsekundy(&zegar2, -40);
    printf("Sekunda: = ");
    drukuj(stdout, zegar2);

    printf("\n");
    printf("Drukuj: ");
    drukuj(stdout, zegar2);

    return 0;
}

void drukuj(FILE *f, Zegar z)
{
   fprintf(f, "%02d:%02d:%02d\n", z.godzina, z.minuta, z.sekunda);
}

void dodajsekundy(Zegar *z, short s)
{
    z->sekunda += s;
    *z = ustaw(z->godzina, z->minuta, z->sekunda);
}

void dodajminuty(Zegar *z, short m)
{
    z->minuta += m;
    *z = ustaw(z->godzina, z->minuta, z->sekunda);
}

void dodajgodziny(Zegar *z, short g)
{
    z->godzina += g;
    *z = ustaw(z->godzina, z->minuta, z->sekunda);
}

Zegar normuj(Zegar z)
{
    return ustaw(z.godzina, z.minuta, z.sekunda);
}

bool sprawdz(Zegar zegar)
{
    if(zegar.godzina < 0 || zegar.godzina >= 24)
    {
        return false;
    }
    if(zegar.minuta < 0 || zegar.minuta >= 60)
    {
        return false;
    }
    if(zegar.sekunda < 0 || zegar.sekunda >= 60)
    {
        return false;
    }

    return true;
}

Zegar ustaw(short g, short m, short s)
{
    Zegar zegar = {};

    if(s >= 0)
    {
        g += s / 3600;
        s %= 3600;
        m += s / 60;
        s %= 60;
    }
    else
    {
        short countOfMinutes = abs(s / 60  - 1);
        m -= countOfMinutes;
        s += countOfMinutes * 60;
    }
    if(m >= 0)
    {
        g += m / 60;
        m %= 60;
    }
    else
    {
        short countOfHours = abs(m / 60 - 1);
        g -= countOfHours;
        m += countOfHours * 60;
    }

    g %= 24;
    if(g < 0)
    {
        g += 24;
    }

    zegar.godzina = g;
    zegar.minuta = m;
    zegar.sekunda  = s;

    return zegar;
}
