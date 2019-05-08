#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef socios_H_INCLUDED
#define socios_H_INCLUDED
#include "socios.h"
#endif // socios_H_INCLUDED

#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED
#include "funciones.h"
#endif // funciones_H_INCLUDED

#ifndef libros_H_INCLUDED
#define libros_H_INCLUDED
#include "libros.h"
#endif // libros_H_INCLUDED

#ifndef autores_H_INCLUDED
#define autores_H_INCLUDED
#include "autores.h"
#endif // autores_H_INCLUDED

#ifndef prestamos_H_INCLUDED
#define prestamos_H_INCLUDED
#include "prestamos.h"
#endif // prestamos_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif // input_H_INCLUDED


void inicializarPrestamo (ePrestamo pres[], int tamPres)
{
    for (int i=0;i<tamPres;i++)
    {
        pres[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarPrestamoLibre (ePrestamo pres[], int tamPres)
{
    int indicePrestamo=-2;

    for (int i=0;i<tamPres;i++)
    {
        if (pres[i].itsEmpty==1)
        {
            indicePrestamo=i;
            break;
        }

    }

    return indicePrestamo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaPrestamo (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc, eLibros lib[], int tamLib, int contador)
{
    int busquedaLegajo;
    int espacioLibre;
    int legajo;
    char respuesta;

    espacioLibre=buscarPrestamoLibre(pres, tamPres);


    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema!!\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

        if (busquedaLegajo==-2)
        {
            printf("\nLegajo inexistente en el sistema!!\n\n");
        }
        else
        {
            printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);
            validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ","Solo 's' o 'n'. Reingrese: ", 's', 'n');

            if (respuesta=='s')
            {
                for (int i=0;i<tamLib;i++)
                {
                    if (lib[i].itsEmpty==0)
                    {
                         printf("%d-%s\n", lib[i].idLibro, lib[i].titulo);
                    }

                }
                getInt(&pres[espacioLibre].idLibro, "Ingrese libro: ", "No entra en el rango. Reingrese: ", 1000, 1004);
                getInt(&pres[espacioLibre].fechaDePrestamo.dia, "Ingrese dia: ", "Fecha no valida. Reingrese: ", 1, 31);
                getInt(&pres[espacioLibre].fechaDePrestamo.mes, "Ingrese mes: ", "Fecha no valida. Reingrese: ", 1, 12);
                getInt(&pres[espacioLibre].fechaDePrestamo.anio, "Ingrese anio: ", "Fecha no valida. Reingrese: ", 2018, 2019);


                pres[espacioLibre].itsEmpty=0;
                pres[espacioLibre].idPrestamo=0;
                pres[espacioLibre].idPrestamo+=contador;
                pres[espacioLibre].legajoEmpleado=legajo;


                printf("\nOperacion exitosa!!\n\n");


            }
            else
            {
                printf("\nOperacion cancelada!!\n\n");
            }

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarPrestamo (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int contador=0;

    printf("PRESTAMO     SOCIO   LIBRO    FECHA\n");

    for (int i=0;i<tamLib;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].idLibro==lib[i].idLibro)
            {
                for (int k=0;k<tamSoc;k++)
                {
                    if (soc[k].legajo==pres[j].legajoEmpleado  && soc[k].itsEmpty==0  && pres[j].itsEmpty==0  && lib[i].itsEmpty==0)
                    {
                         printf("  %04d       %04d   %04d   %02d/%02d/%02d\n", pres[j].idPrestamo, soc[k].legajo, lib[i].idLibro, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                         contador++;
                    }
                }
            }
        }
    }
    if (contador==0)
    {
        printf("\nNo hay libros prestados!!\n\n");
    }
}

