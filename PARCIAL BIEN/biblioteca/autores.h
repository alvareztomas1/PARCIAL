
#ifndef socios_H_INCLUDED
#define socios_H_INCLUDED
#include "socios.h"
#endif // socios_H_INCLUDED

/** \brief Recorre todo el array de estructura eAutor y le da valor 1 al campo itsEmpty
 *
 * \param  aut Array de estructuras a recorrer
 * \param  tamAut El tamaño de la estructura recorrida
 * \return  Void
 *
 */

void inicializarAutores (eAutor aut[], int tamAut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Imprime los datos del autor recibido
 *
 * \param aut Estructura de tipo eAutor a imprimir
 * \return Void
 *
 */

void mostrarAutor (eAutor aut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recorre el array de estructura eAutor e imprime los datos de los autores que tengan itsEmpty valiendo 0
 *
 * \param aut Array de estructuras a recorrer
 * \param tamAut Tamaño de la estructura
 * \return Void
 *
 */

void mostrarAutores (eAutor aut[], int tamAut);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Ordena los datos de los autores por apellido y nombre
 *
 * \param aut Array de estructuras en la que se ordenaran los datos
 * \param tamAut Tamaño de la estructura
 * \return Void
 *
 */

void ordenarAutores (eAutor aut[], int tamAut);
