

typedef struct
{
    int dia, mes, anio;

}eFecha;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int legajo;
    char apellido[31];
    char nombre [31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaDeIngreso;
    int itsEmpty;

}eSocio;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idPrestamo;
    int idLibro;
    int legajoEmpleado;
    eFecha fechaDePrestamo;
    int itsEmpty;

}ePrestamo;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idAutor;
    char apellido[31];
    char nombre[31];
    int itsEmpty;

}eAutor;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int idLibro;
    char titulo[51];
    int idAutor;
    int itsEmpty;

}eLibros;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Menu para ingresar los datos
 *
 * \return opcion ingresada por el usuario
 *
 */

int menu();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recorre todo el array de estructura eSocio y le da valor 1 al campo itsEmpty
 *
 * \param  soc Array de estructura a recorrer
 * \param  tamSoc El tamaño de la estructura recorrida
 * \return  Void
 *
 */

void inicializarEmpleados (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Inicializa los valores de los campos de las estructuras
 *
 * \param  soc Array de Estructura socios a la que se le cargan valores
 * \param  tamSoc Tamaño de la estructura soc
 * \param  lib Array de estructuras libros a la que se le cargan valores
 * \param  tamSec Tamaño de la estructura sec
 * \param  pres Array de estructuras prestamos a la que se le cargan valores
 * \param  tamPres Tamaño de la estructura pres
 * \return void
 *
 */

void hardcode (eSocio soc[], int tamSoc, eAutor aut[], int tamAut, eLibros lib[], int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Busca el campo legajo de un empleado
 *
 * \param soc Array de Estructura a recorrer
 * \param tamSoc Tamaño de la estructura
 * \param legajo Legajo ingresado por el usuario que se compara con los que ya estan dados de alta
 * \return El indice del legajo.
 *
 */

int buscarLegajo (eSocio soc[], int tamSoc, int legajo);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Busca en el array de estructuras que hay algun campo itsEmpty que valga 1
 *
 * \param soc Array de Estructura a recorrer
 * \param tamSoc Tamaño de la estrucura
 * \return indice donde encontro el itsEmpty = 1 o -2 si no encuentra nada
 *
 */

int buscarLibre (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Pide los datos al usuario, verifica que esten bien, de ser asi da de alta al socio
 *
 * \param soc Array de Estructuras donde se guardan los datos del socio
 * \param tmaSoc Tamaño de la estructura
 * \param contador Me permite volver autoincremental el campo legajo
 * \return Void
 *
 */

void altaSocio (eSocio soc[], int tamSoc, int contador);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Imprime los datos del socio recibido
 *
 * \param soc Estructura de tipo eSocio a imprimir
 * \return Void
 *
 */

void mostrarSocio (eSocio soc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Recorre el array de estructura eSocios e imprime los datos de los socios que tengan itsEmpty valiendo 0
 *
 * \param soc Array de estructuras a recorrer
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */
void mostrarSocios (eSocio soc[], int tamSoc);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Pide el legajo de algun socio y si el usuario acepta da de baja a la persona cambiando el valor de itsEmpty a -1
 *
 * \param soc Array de estructuras donde se cambiara el valor de itsEmpty si el legajo ingresado existe
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */
void bajaSocio (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Ordena los datos de los socios por apellido y nombre
 *
 * \param soc Array de estructuras en la que se ordenaran los datos
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */
void ordenarSocios (eSocio soc[], int tamSoc);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Permite al usuario cambiar los datos de un socio ya ingresado
 *
 * \param soc Array de estructura donde se modificara los datos del socio en caso de que exista
 * \param tamSoc Tamaño de la estructura
 * \return Void
 *
 */
void modificarSocio (eSocio soc[], int tamSoc);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeLibro (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarAutorConMasLibros (eAutor aut[], int tamAut, eLibros lib[], int tamLib);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void informarPrestamosDeUnSocio (eSocio soc[],int tamSoc,eAutor aut[],int tamAut,ePrestamo pres[], int tamPres);

