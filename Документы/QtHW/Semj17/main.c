#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str [] = {"О сколько нам открытий чудных Готовят просвещенья дух И опыт, сын ошибок трудных, И гений, парадоксов друг, И случай, бог изобретатель. А. С. Пушкин."};

int DeleteSpace(char* str);

int main()
{
    DeleteSpace(str);
    return 0;
}
int DeleteSpace(char* str)
{
    int strstrlen = strlen(str);

    int j = 0;

    char nospacesstr[strstrlen];

    for(int count = 0; count < strstrlen ;count++)
    {
        if(str[count] !=' ')
        {
            nospacesstr[j] = str[count];
            j++;
        }
    }
  return printf("%s",nospacesstr);
}
