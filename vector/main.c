#include <stdio.h>
#include <string.h>

#include "vector.h"

int comp(Element*, Element*);
void printVector(Vector*);

typedef enum
{
    black,
    white,
    green,
    ellow,
    red
} Color;

typedef struct
{
    char firstName[20];
    char lastName[30];
    uint old;
} Man;

typedef struct
{
    char brand[20];
    char model[30];
    Color color;
    uint price;
} Car;

typedef struct
{
    char name[30];
    int year;
} City;

char *colorName[] = { "Черный", "Белый", "Зеленый", "Желтый", "Красный" };

int main()
{
    Man savelyi = {"Савелий", "Савельев", 25};

    Car car = {"Toyota", "LC100", black, 3000000};

    City city = {"Моздок", 1763};

    Element pElement[7] = {
                            {&savelyi, 0},
                            {"Вася", 1},
                            {"Петро", 1},
                            {&car, 2},
                            {"Анатолий", 1},
                            {"Инокентий", 1},
                            {&city, 3}
                          };

    Vector *pMyVector = initVector(10, 5);

    if(pMyVector)
    {
        for(int count = 0; count < 4; count++)
        {
            appendVector(pMyVector, &pElement[count]);
        }

        sortVector(pMyVector, comp);

        printVector(pMyVector);
        deleteVector(pMyVector);
    }
  return 0;
}

void printVector(Vector *pVector)
{
    for(uint count = 0; count < pVector->_usedLength; count++)
    {
        switch(pVector->_pElements[count]->_type)
        {
            case 0:
                {
                    Man *pTmpMan = pVector->_pElements[count]->_data;
                    printf("Имя : %s, Фамилия : %s, Возраст : %d\n", pTmpMan->firstName, pTmpMan->lastName, pTmpMan->old);
                }
            break;
            case 1:
                {
                    printf("Имя : %s\n", (char*)pVector->_pElements[count]->_data);
                }
            break;
            case 2:
                {
                    Car *pTmpCar = pVector->_pElements[count]->_data;
                    printf("Производитель : %s, Модель : %s, Цвет : %s, Цена : %u руб.\n",  pTmpCar->brand,
                                                                                       pTmpCar->model,
                                                                                       colorName[pTmpCar->color],
                                                                                       pTmpCar->price);
                }
            break;
        }
    }
}

int comp(Element *e1, Element *e2)
{
    int compTmp = 0;

    if(e1->_type == 0 && e2->_type == 0)
    {
        Man *man = e1->_data;
        Man *man2 = e2->_data;
        compTmp = strlen(man->firstName) - strlen(man2->firstName);
    }
    if(e1->_type == 0 && e2->_type == 1)
    {
        Man *man = e1->_data;
        char *name = e2->_data;
        compTmp = strlen(man->firstName) - strlen(name);
    }
    if(e1->_type == 0 && e2->_type == 2)
    {
        Man *man = e1->_data;
        Car *car = e2->_data;
        compTmp = strlen(man->firstName) - strlen(car->model);
    }
    if(e1->_type == 0 && e2->_type == 3)
    {
        Man *man = e1->_data;
        City *city = e2->_data;
        compTmp = strlen(man->firstName) - strlen(city->name);
    }
    if(e1->_type == 1 && e2->_type == 0)
    {
        char *name = e1->_data;
        Man *man = e2->_data;
        compTmp = strlen(name) - strlen(man->firstName);
    }
    if(e1->_type == 1 && e2->_type == 1)
    {
        char *name = e1->_data;
        char *name2 = e2->_data;
        compTmp = strlen(name) - strlen(name2);
    }
    if(e1->_type == 1 && e2->_type == 2)
    {
        char *name = e1->_data;
        Car *car = e2->_data;
        compTmp = strlen(name) - strlen(car->model);
    }
    if(e1->_type == 1 && e2->_type == 3)
    {
        char *name = e1->_data;
        City *city = e2->_data;
        compTmp = strlen(name) - strlen(city->name);
    }
    if(e1->_type == 2 && e2->_type == 0)
    {
        Car *car = e1->_data;
        Man *man = e2->_data;
        compTmp = strlen(car->model) - strlen(man->firstName);
    }
    if(e1->_type == 2 && e2->_type == 1)
    {
        Car *car = e1->_data;
        char *name= e2->_data;
        compTmp = strlen(car->model) - strlen(name);
    }
    if(e1->_type == 2 && e2->_type == 2)
    {
        Car *car = e1->_data;
        Car*car2 = e2->_data;
        compTmp = strlen(car->model) - strlen(car2->model);
    }
    if(e1->_type == 2 && e2->_type == 3)
    {
        Car *car = e1->_data;
        City *city = e2->_data;
        compTmp = strlen(car->model) - strlen(city->name);
    }
    if(e1->_type == 3 && e2->_type == 0)
    {
        City *city = e1->_data;
        Man *man = e2->_data;
        compTmp = strlen(city->name) - strlen(man->firstName);
    }
    if(e1->_type == 3 && e2->_type == 1)
    {
        City *city = e1->_data;
        char *name = e2->_data;
        compTmp = strlen(city->name) - strlen(name);
    }
    if(e1->_type == 3 && e2->_type == 2)
    {
        City *city = e1->_data;
        Car *car = e2->_data;
        compTmp = strlen(city->name) - strlen(car->model);
    }
    if(e1->_type == 3 && e2->_type == 3)
    {
        City *city = e1->_data;
        City *city2 = e2->_data;
        compTmp = strlen(city->name) - strlen(city2->name);
    }
  return compTmp;
}
