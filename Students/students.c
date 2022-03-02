#include <stdlib.h>
#include <stdio.h>

#include "students.h"

uint saveVectorStudents(Vector *pVector, FILE *pFile)
{
    for(uint count = 0; lengthVector(pVector); count++)
    {
        Element *pElement = atFromVector(pVector, count);
        Student *pStudent = pElement->_data;
        fwrite(pStudent, sizeof(Student), 1, pFile);
    }
  return lengthVector(pVector);
}

uint loadVectorStudents(Vector *pVector, FILE *pFile)
{
    for(uint count = 0; count < lengthVector(pVector); count++)
    {
        Element *element = malloc(sizeof(Element));
        element->_data = malloc(sizeof(Student));
        element->_type = 's';
        fread(element->_data, sizeof(Student), 1, pFile);
        appendToVector(pVector, element);
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
    printf("Введите фамилию: ");
    scanf("%s", newStudent->lastName);
    printf("\n");
    printf("Введите имя: ");
    scanf("%s", newStudent->firstName);
    printf("\n");
    printf("Введите пол('М' или 'Д'): ");
    scanf("%s", newStudent->gender);
    printf("\n");
    printf("Введите класс: ");
    scanf("%s", newStudent->class);
    printf("\n");
    printf("Введите школу: ");
    scanf("%s", newStudent->schoolName);
    printf("\n");

    Element* newElement = malloc(sizeof(Element));
    newElement->_data = newStudent;
    newElement->_type = 's';

    appendToVector(pVector, newElement);

  return newStudent;
}

bool showVectorStudents(Vector *pVector) // ???
{
    Element *pElement = *pVector->_pElements;
    Student *pStudent = pElement->_data;

    printf("%c\n", *pStudent->firstName);
    printf("%c\n", *pStudent->lastName);
    printf("%s\n",  pStudent->gender);
    printf("%c\n", *pStudent->class);
    printf("%c\n", *pStudent->schoolName);

  return true;
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

int Run(int item)
{
    if(item == 1)
    {

    }
    else if(item == 2)
         {

         }
         else if(item == 3)
              {

              }
              else if(item == 4)
                   {

                   }
                   else if(item == 5)
                        {

                        }

}
