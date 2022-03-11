#include <stdio.h>
#include <stdlib.h>

#include "students.h"

uint getMenuItem();
_bool run(Vector*);

void sig(int n)
{
}

int main()
{
    char *fullNameOfDataBase = "students.db";
    bool exitCode = _true;
    Vector *students = initVector(10, 5);

    FILE* pFile = newFile(fullNameOfDataBase);

    if(students && pFile)
    {
        loadVectorStudents(students, pFile);
        fclose(pFile);

        exitCode = run(students);

        pFile = fopen(fullNameOfDataBase, "wb");
        saveVectorStudents(students, pFile);
        fclose(pFile);

    deleteVector(students);
    }

  return exitCode;
}

uint getMenuItem()
{
    printw("%s", "1. Append student !\n"); //"1. Добавить студента !\n"
    printw("%s", L"2. Удалить студента !\n");
    printw("%s", L"3. Изменить студента !\n");
    printw("%s", L"4. Вывести данные студента !\n");
    printw("%s", L"5. Вывести всех студентов !\n\n");
    printw("%s", "-------------------------------\n");
    printw("%s", L"0. Выход !\n");

    refresh();

    int item = 0;
    do
    {
        scanf("%d", &item);
    }
    while(item < 0 || item > 5);

  return item;
}

uint isValidStudent(Vector* pVector)
{
    int number;
    printf("Введите номер студента : ");
    scanf("%d/n", &number);
    while (number < 0 || number >= (int)lengthVector(pVector))
    {
        printf("Введите корректоный номер студента : ");
        scanf("%d/n", &number);
    }

    return number;
}

_bool run(Vector *pVector)
{
    int item;

    setlocale(LC_ALL, "");
    signal(SIGINT, sig);
    initscr();

    do
    {
        item = getMenuItem();

        switch(item)
        {
            case 1:
                appendNewStudent(pVector);
            break;
            case 2:
                deleteAtNumberStudent(isValidStudent(pVector), pVector);
            break;
            case 3:
                editStudent(atVectorStudent(pVector, isValidStudent(pVector)));
            break;
            case 4:
            {
               int n = isValidStudent(pVector);
               Student *pS = atVectorStudent(pVector, n);
               showStudent(pS);
            }
            break;
            case 5:
                showVectorStudents(pVector);
            break;
        }

        printf("Нажмите на любую клавишу для продолжения ...\n ");

        getch();

        clear();
    }
    while(item != 0);

    endwin();

  return _true;
}

