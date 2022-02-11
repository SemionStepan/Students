#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define END_OF_STRING '\0'

char* deleteSpace(char*);
void copyString(char*, char*);

int main()
{
    char str[] = {"О сколько нам открытий чудных Готовят просвещенья дух И опыт, сын ошибок трудных, И гений, парадоксов друг, И случай, бог изобретатель. А. С. Пушкин."};

    printf("%s", deleteSpace(str));

    return 0;
}
char* deleteSpace(char* str)
{
    for(int i = 0; str[i] != END_OF_STRING; i++)
    {
        if(str[i] == ' ')
        {
            copyString(str+i, str+(i+1));
        }
    }
  return str;
}

void copyString(char* pStr, char* pStr1)
{
    while(*pStr1 != END_OF_STRING)
    {
        *pStr++ = *pStr1++;
    }
    *pStr = END_OF_STRING;
}
