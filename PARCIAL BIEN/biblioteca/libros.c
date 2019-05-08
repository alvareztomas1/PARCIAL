#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>



#ifndef libros_H_INCLUDED
#define libros_H_INCLUDED
#include "libros.h"
#endif // libros_H_INCLUDED



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarLibros (eLibros lib[], int tamLib)
{
    for (int i=0;i<tamLib;i++)
    {
        lib[i].itsEmpty=1;
    }
}

void ordenarLibros (eLibros lib[], int tamLib)
{
    eLibros aux;

    for (int i=0;i<tamLib-1;i++)
    {
        for (int j=i+1;j<tamLib;j++)
        {
            if (strcmp(lib[i].titulo, lib[j].titulo)>0)
            {
                aux=lib[i];
                lib[i]=lib[j];
                lib[j]=aux;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarLibro (eLibros lib)
{
    printf("%4d  %15s  %3d\n", lib.idLibro, lib.titulo, lib.idAutor);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarLibros (eLibros lib[], int tamLib)
{
    int contador=0;

    printf ("ID LIBRO       TITULO  ID AUTOR\n");

    for (int i=0;i<tamLib;i++)
    {
        if (lib[i].itsEmpty==0)
        {
            mostrarLibro(lib[i]);
            contador++;
        }

    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}
