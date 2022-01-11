#include "sort.h"

#define STUDENTS_NUMBER 7

void printStudents(Student*, uint);

float weightStudentCompare(const void*, const void*);
float heightStudentCompare(const void* a1, const void* a2);
float FirstNameStudentCompare(const void* a1, const void* a2);
float LastNameStudentCompare(const void* a1, const void* a2, const uint sizeofElement);

int main()
{
    Student studentArray[STUDENTS_NUMBER] = {   {"Оля", "Иванова", 160, 46, {01,03,2007}, Woman},
                                                {"Данила", "Скоробогатов", 160, 44, {14,05,2007}, Man},
                                                {"Лев", "Макаров", 185, 65, {07,11,2006}, Man},
                                                {"Иван", "Ванисов", 170, 60, {21,04,2005}, Man},
                                                {"Маша", "Петрова", 159, 43, {03,01,2005}, Woman},
                                                {"Глеб", "Лихоман", 145, 42, {01,03,2007}, Man},
                                                {"Михаил", "Соколов", 165, 46, {27,06,2006}, Man}
                                            };
    printf("Сортировка по фамилии :\n");
    printStudents(sort(studentArray, STUDENTS_NUMBER, sizeof(Student), LastNameStudentCompare), STUDENTS_NUMBER);

  return 0;
}

void printStudents(Student *pStudentArray, uint sizeArray)
{
    char *gender[] = {"мужской", "женский"};

    for(uint count = 0; count < sizeArray; count++)
    {
        printf("Имя: %s Фамилия: %s | Рост: %3.2f | Вес: %3.2f | %d.%d.%d | Пол: %s\n", pStudentArray[count].firstName,
                                                                           pStudentArray[count].lastName,
                                                                           pStudentArray[count].height,
                                                                           pStudentArray[count].weight,
                                                                           pStudentArray[count].dateOfBirth.day,
                                                                           pStudentArray[count].dateOfBirth.month,
                                                                           pStudentArray[count].dateOfBirth.year,
                                                                           gender[pStudentArray[count].gender]
        );
    }
}

float weightStudentCompare(const void* a1, const void* a2)
{
  return (float)((Student*)a1)->weight - ((Student*)a2)->weight;
}

float heightStudentCompare(const void* a1, const void* a2)
{
  return (float)((Student*)a1)->height - ((Student*)a2)->height;
}

float FirstNameStudentCompare(const void* a1, const void* a2)
{
    int len = strlen(((Student*)a1)->firstName) - strlen(((Student*)a2)->firstName);
  return len;
}
float LastNameStudentCompare(const void* a1, const void* a2, const uint sizeofElement)
{
    void *A1lastName = malloc(sizeofElement);
    memcpy(A1lastName, ((Student*)a1)->lastName, sizeof((Student*)a1)->lastName);
    int one = strlen(A1lastName);

    void *A2lastName = malloc(sizeofElement);
    memcpy(A2lastName, ((Student*)a2)->lastName, sizeof((Student*)a2)->lastName);
    int two = strlen(A2lastName);

  return one - two;
    free(A1lastName);
    free(A2lastName);
}
