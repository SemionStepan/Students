#include <stdio.h>
#include <stdlib.h>

#include "students.h"

uint getMenuItem();

int main()
{
    char *nameOfDataBase = "strudents.db";

    Vector *students = initVector(10, 5);

    getMenuItem();

    system("clear");

    FILE *pFile = fopen(nameOfDataBase, "");
    if(students && pFile)
    {
        if(loadVectorStudents(students, pFile) > 0)
        {

//            editStudent(student);
//            showVectorStudents(students);

            pFile = fopen(nameOfDataBase, "w");
            saveVectorStudents(students, pFile);
            fclose(pFile);
        }
    deleteVector(students);
    }

  return 0;
}

uint getMenuItem()
{
    printf("1. Добавить студента !\n");
    printf("2. Удалить студента !\n");
    printf("3. Изменить студента !\n");
    printf("4. Вывести данные студента !\n");
    printf("5. Вывести всех студентов !\n");

    int item = 0;

    while(item < 1 || item > 5)
    {
        scanf("%d", &item);
    }

  return item;
}
