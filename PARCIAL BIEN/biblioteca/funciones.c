#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED
#include "funciones.h"
#endif // funciones_H_INCLUDED

void validarDosChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    printf("%s", message);
    fflush(stdin);
    *input=getche();
    printf("\n");
    system("pause");


    *input = tolower(*input);

    while (*input != lowLimit && *input != hiLimit)
    {
        printf("\n");
        printf(eMessage);
        printf("\n\n");
        printf(message);

        scanf("%c", input);
        fflush(stdin);
        *input = tolower(*input);
    }
}


