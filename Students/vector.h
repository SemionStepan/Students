#ifndef VECTOR_H
#define VECTOR_H

// Структура логики : истина или ложь.
typedef enum
{
    true,
    false
} bool;

// Новый тип знаковое целое.
typedef unsigned int uint;

typedef unsigned char uchar;

typedef unsigned long int ulint;

// Структура, обозначающая элемент(указатель на данные, тип элемента)
typedef struct
{
    void *_data;
    uchar _type;
} Element;

// Структура, которая хранит в себе свободное место, занятое место, и ук4азатель на элемент
typedef struct
{
    uint _delta;
    uint _usedLength;
    uint _fullLength;
    Element** _pElements;
} Vector;

// Функция, создающая вектор
// Аргумент - целое число, обозначающее выделенное пустое место
// Возвращает указатель на новый вектор
Vector* initVector(uint, uint);

// Функция, удаляющая вектор (не завершена)
// Аргумент - указатель на вектор
// ---
void deleteVector(Vector*);

// Функция, добавляющая элемент в вектор
// Аргументы - указатель на вектор, указатель на элемент
// Возвращает указатель на элемент
Element* appendToVector(Vector*, Element*);

// Функция, добавляющая в элемент вектора элемент по номеру
// Аргументы - указатель на вектор, номер, указатель на элемент
// Возвращает элемент
Element* insertToVector(Vector*, uint, Element*);

// Функция, удаляющая элемент из вектора
// Аргументы - указатель на вектор, номер элемента
// Возвращает элемент
Element* removeFromVector(Vector*, uint);

// Функция, выдающая элемент по его номеру
// Аргументы - указатель на вектор, номер нужного елемента
// Возвращает элемент
Element* atFromVector(Vector*, uint);

// Функция, сортирующая векторы по сравнению
// Аргументы - указатель на вектор, указатель на сравнение
// Возвращает вектор
Vector* sortVector(Vector*, int (*)(Element*, Element*));

// Функция, выдающая длину вектора
// Аргумент - указатель на вектор
// Возвращает длину вектора
uint lengthVector(Vector*);

//
//
//
Vector* plusVector(Vector*, Vector*);

#endif // VECTOR_H
