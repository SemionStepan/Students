#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>

#include "vector.h" 

typedef struct
{
    char firstName[30];
    char lastName[30];
    char gender[2];
    char class[5];
    char schoolName[50];
} Student;

// Функция, загружающая студентов из файла в вектор
// Аргументы - указатель на вектор, файл
// Возвращает длину вектора
uint loadVectorStudents(Vector*, FILE*);

// Функция, сохраняющая студентов из вектора в файл
// Аргументы - указатель на вектор, файл
// Возвращает длину вектора
uint saveVectorStudents(Vector*, FILE*);

//
//
//
Student* atVectorStudent(Vector*, uint);

// Функция, создающая и заполняющая студента
// Аргумент - вектор
// Возвращает указатель на студента
Student* appendNewStudent(Vector*);

// Функция, редактирующая студента
// Аргумент - студент
// Возвращает указатель на студента
Student* editStudent(Student*);

//
//
//
bool showStudent(Student*);

//
//
//
bool showVectorStudents(Vector*);

int forMenu(int);

#endif // STUDENTS_H
