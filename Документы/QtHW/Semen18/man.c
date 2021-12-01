#include <stdlib.h>
#include <stdio.h>

#include "man.h"

Man *initMan(uint size)
{
    Man *pTmpMan = malloc(sizeof(Man)*size);
    for(uint i = 0; i < size; i++)
    {
        printf("Введите имя : ");
        scanf("%s", (pTmpMan+i)->firstName);
        printf("\n");

        printf("Введите фамилию : ");
        scanf("%s", (pTmpMan+i)->lastName);
        printf("\n");

        printf("Введите рост : ");
        scanf("%f", &(pTmpMan+i)->height);
        printf("\n");

        printf("Введите вес : ");
        scanf("%f", &(pTmpMan+i)->weight);
        printf("\n");

        printf("Введите день рождения : ");
        scanf("%u", &(pTmpMan+i)->birthday.day);
        printf("\n");
        printf("Введите месяц рождения : ");
        scanf("%u", &(pTmpMan+i)->birthday.month);
        printf("\n");
        printf("Введите год рождения : ");
        scanf("%u", &(pTmpMan+i)->birthday.year);
        printf("\n");

        printf("Введите цвет кожи (1-чёрный, 2-белый, 3-красный) : ");
        scanf("%u", &(pTmpMan+i)->skinColor);
        printf("\n");

        printf("Введите национальность (1-русский, 2- не русский) : ");
        scanf("%u", &(pTmpMan+i)->nationality);
        printf("\n");
    }

  return pTmpMan;
}

void printMan(Man *pMan, uint size)
{   
    for(uint i = 0; i < size; i++)
    {
    printf("\nИмя : %s\n", (pMan+i)->firstName);
    printf("Фамилия : %s\n", (pMan+i)->lastName);
    printf("Рост : %4.2f\n", (pMan+i)->height);
    printf("Вес : %4.2f\n", (pMan+i)->weight);
    printf("День рождения : %u\n", (pMan+i)->birthday.day);
    printf("Месяц рождения : %u\n", (pMan+i)->birthday.month);
    printf("Год рождения : %u\n", (pMan+i)->birthday.year);
    printf("Цвет кожи(1-чёрный, 2-белый, 3-красный) : %u\n", (pMan+i)->skinColor);
    printf("Национальность(1-русский, 2- не русский) : %u\n\n", (pMan+i)->nationality);
    }
}

bool saveMan(Man *pMan, const char *pFileName, uint size)
{
    for(uint i = 0; i < size; i++)
    {

        FILE *pFile = fopen(pFileName, "w");
        if(!pFile)
        {
            return false;
        }

        fwrite(pMan, sizeof(Man), size, pFile);
        fclose(pFile);
    return true;
    }
  return 0;
}

bool loadMan(const char *pFileName, Man *pMan, uint size)
{
    for(uint i = 0; i < size; i++)
    {
    FILE *pFile = fopen(pFileName, "r");
    if(!pFile)
    {
        return false;
    }

    fread(pMan, sizeof(Man), size, pFile);
    fclose(pFile);
  return true;
    }
  return 0;
}
