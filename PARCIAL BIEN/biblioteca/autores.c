#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


#ifndef autores_H_INCLUDED
#define autores_H_INCLUDED
#include "autores.h"
#endif // autores_H_INCLUDED



void inicializarAutores (eAutor aut[], int tamAut)
{
    for (int i=0;i<tamAut;i++)
    {
        aut[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarAutores (eAutor aut[], int tamAut)
{
    eAutor aux;

    for (int i=0;i<tamAut-1;i++)
    {
        for (int j=i+1;j<tamAut;j++)
        {
            if (strcmp(aut[i].apellido, aut[j].apellido)>0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
            else if (strcmp(aut[i].apellido, aut[j].apellido)>0 && strcmp(aut[i].nombre, aut[j].nombre)>0)
            {
                aux=aut[i];
                aut[i]=aut[j];
                aut[j]=aux;
            }
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAutor (eAutor aut)
{
    printf("%4d  %15s  %15s\n", aut.idAutor, aut.apellido, aut.nombre);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarAutores (eAutor aut[], int tamAut)
{
    int contador=0;

    printf ("ID AUTOR       APELLIDO         NOMBRE\n");

    for (int i=0;i<tamAut;i++)
    {
        if (aut[i].itsEmpty==0)
        {
            mostrarAutor(aut[i]);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

