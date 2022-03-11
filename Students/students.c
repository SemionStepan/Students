#include <stdlib.h>
#include <stdio.h>

#include "students.h"

FILE* newFile(char *fullNameOfDataBase)
{
    FILE *pFile = fopen(fullNameOfDataBase, "rb");
    if(!pFile)
    {
        pFile = fopen(fullNameOfDataBase, "wb");
        fclose(pFile);
        pFile = fopen(fullNameOfDataBase, "rb");
    }

    return pFile;
}

uint saveVectorStudents(Vector *pVector, FILE *pFile)
{
    for(uint count = 0; count < lengthVector(pVector); count++)
    {
        Element *pElement = atFromVector(pVector, count);
        Student *pStudent = pElement->_data;
        fwrite(pStudent, sizeof(Student), 1, pFile);
    }
  return lengthVector(pVector);
}

uint loadVectorStudents(Vector *pVector, FILE *pFile)
{
    Student student;
    while(!feof(pFile))
    {
        if(fread(&student, sizeof(Student), 1, pFile) == 1)
        {
            Element *element = malloc(sizeof(Element));
            element->_data = malloc(sizeof(Student));
            element->_type = 's';
            memcpy(element->_data, &student, sizeof(Student));

            appendToVector(pVector, element);
        }
    }
  return lengthVector(pVector);
}

Student* atVectorStudent(Vector* pVector, uint number)
{
  if(number < 0 || number > pVector->_usedLength)
  {
    return NULL;
  }

  return (Student*)pVector->_pElements[number]->_data;
}

Student* appendNewStudent(Vector* pVector)
{
    Student* newStudent = malloc(sizeof(Student));

    editStudent(newStudent);

    Element* newElement = malloc(sizeof(Element));
    newElement->_data = newStudent;
    newElement->_type = 's';

    appendToVector(pVector, newElement);

  return newStudent;
}

void showStudent(Student *pStudent)

{
    printw("Фамилия : %s\n", pStudent->lastName);
    printw("Имя : %s\n", pStudent->firstName);
    printw("Пол : %c\n",  *pStudent->gender);
    printw("Класс : %s\n", pStudent->class);
    printw("Школа : %s\n\n", pStudent->schoolName);
}

void showVectorStudents(Vector* pVector)

{
    for(uint count = 0; count < pVector->_usedLength; count++)
    {
      showStudent(pVector->_pElements[count]->_data);
    }
}

Student* editStudent(Student* pStudent)
{
    printf("Введите фамилию: ");
    scanf("%s", pStudent->lastName);
    printf("\n");
    printf("Введите имя: ");
    scanf("%s", pStudent->firstName);
    printf("\n");
    printf("Введите пол('М' или 'Д'): ");
    scanf("%s", pStudent->gender);
    printf("\n");
    printf("Введите класс: ");
    scanf("%s", pStudent->class);
    printf("\n");
    printf("Введите школу: ");
    scanf("%s", pStudent->schoolName);
    printf("\n");

  return pStudent;
}

_bool deleteAtNumberStudent(uint number, Vector* pVector) //новая
{
    if(removeFromVector(pVector, number))
    {
        return _false;
    }

    return _true;
}
