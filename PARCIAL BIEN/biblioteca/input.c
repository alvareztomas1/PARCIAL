#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif // input_H_INCLUDED


int getInt (int* input, char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk = -1;
    int valor;

    printf("%s", message);
    scanf("%d", &valor);

    while(valor<lowLimit || valor> hiLimit)
    {
        printf(eMessage);
        scanf("%d", &valor);
    }

    *input=valor;
    todoOk=0;

    return todoOk;
}

//--------------------------------------------------------------------------------------
int getFloat (float* input, char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk = -1;
    float valor;

    printf("%s", message);
    scanf("%f", &valor);

    while(valor<lowLimit || valor>hiLimit)
    {
        printf(eMessage);
        scanf("%f", &valor);
    }

    *input=valor;
    todoOk=0;



    return todoOk;
}
//--------------------------------------------------------------------------------------
int getChar (char* input, char *message, char *eMessage, char lowLimit, char hiLimit)
{
     int todoOk = -1;

    printf ("%s", message);
    fflush(stdin);
    scanf ("%c", input);

    while(*input>hiLimit || *input<lowLimit)
    {
       printf ("%s", eMessage);
       fflush(stdin);
       scanf  ("%c", input);
    }

    todoOk=0;

    return todoOk;
}
//--------------------------------------------------------------------------------------
int getString(char input[], char *message, char *eMessage, int lowLimit, int hiLimit)
{
    int todoOk=-1;

    system("cls");
    printf ("%s",message);
    fflush(stdin);
    scanf("%s", input);

    while(strlen(input)>hiLimit || strlen(input)<lowLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%s", input);


    }
        todoOk=0;


     return todoOk;

}


