#include <stdio.h>

#include "man.h"

int main()
{
    int size = 0;

    printf("Введите количество человек : ");
    scanf("%d", &size);
    printf("\n");

    const char *pFileName = "/home/semen/Документы/Кьют дз/Semen18/man.m"; 
    Man *pMan = initMan(size);

    saveMan(pMan, pFileName,size);

    loadMan(pFileName, pMan,size);

    printMan(pMan,size);

  return 0;
}
