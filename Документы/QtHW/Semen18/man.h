#ifndef MAN_H
#define MAN_H

typedef unsigned int uint; //Сокращение unsigned int

typedef enum // Логическая переменная bool в которой true или false
{
    true,
    false
}
bool;

typedef enum  // Переменная Цвет кожи
{
    Black,
    White,
    Red
}
SkinColor;

typedef enum //Переменная Национальность
{
    Russian,
    NoRussian
}
Nationality;

typedef struct // Переменная Дата рождения
{
    uint day;
    uint month;
    uint year;
} Birthday;

typedef struct // Основная стуктура Человек
{
    char firstName[20];
    char lastName[30];
    Birthday birthday;
    float height;
    float weight;
    SkinColor skinColor;
    Nationality nationality;
} Man;

Man* initMan(uint size);// функция инициализации Человека
bool saveMan(Man* pMan, const char *pFileName, uint size);// Функция сохранения Человека
bool loadMan(const char *pFileName, Man* pMan, uint size);//Функиция загрузки Человека
void printMan(Man* pMan, uint size);//Вывод Человека

#endif // MAN_H
