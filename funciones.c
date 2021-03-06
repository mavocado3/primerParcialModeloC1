#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"


/** \brief inicializa el array de estructuras
 *
 * \param eProductos* pProducto puntero del array a inicializar
 * \param int length tama�o maximo del array
 * \return devuelve -1 si no lo pudo inicializar (pProducto == NULL o length < 0)
 *         y 0 si esta ok
 */

int initArray(eProductos* pProducto, int length)
{
    int retorno = -1;
    int i;
    if(pProducto != NULL && length> 0)
    {
        for(i=0;i<length;i++)
        {
            pProducto[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
/** \brief crea un menu segun los parametros pasados por el usuario
 *
 * \param char textomenu[] Es la cadena que sirve como menu a ser mostrado
 * \param char min valor minimo que puede tomar el menu
 * \param char min valor maximo que puede tomar el menu
 * \return la opcion elegida por el usuario segun los parametros min y max
 *
 */

char mostrarMenu( char textomenu[], char min, char max )
{
    char opcion ='|';
    int flagPrimera = 1;


    do
    {
        if((opcion < min || opcion > max) && flagPrimera != 1)
        {
            printf("ERROR: reingrese\n");
        }
        printf("%s", textomenu);
        fflush(stdin);
        scanf("%c",&opcion);
        flagPrimera = 0;
    }while(opcion < min || opcion > max);
    return opcion;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param cantidadItems la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibre(eProductos lista[],int cantidadItems)
{
    int index = -1;
    int i;

    for(i= 0; i<cantidadItems; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}


/**
* \brief Solicita un n�mero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxInt;
    int flag = -1;
    int resp;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%d", &auxInt);
    if(resp == 1)
    {
        if(auxInt > lowLimit && auxInt < hiLimit)
        {
            *input = auxInt;
            flag = 0;
        }
    }
    if(flag == -1)
    {
        system("cls");
        printf("%s", eMessage);
    }
    return flag;
}


/**
* \brief Solicita un n�mero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float auxFloat;
    int resp;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%f", &auxFloat);
    if(resp == 1)
    {
        if(auxFloat >= lowLimit && auxFloat <= hiLimit)
        {
            *input = auxFloat;
            return 0;

        }

    }


    printf("%s", eMessage);
    return -1;
}

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud m�nima de la cadena
* \param hiLimit Longitud m�xima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    printf("%s", message);
    fflush(stdin);
    gets(auxChar);
    if(strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit )
    {
            strcpy(input, auxChar);
            return 0;
    }
    printf("%s", eMessage);
    return -1;
}


/**
* \brief Solicita una cadena de caracteres de solo letras y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud m�nima de la cadena
* \param hiLimit Longitud m�xima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char auxChar[50];
    int resp;
    int flagName = 1;
    int i;
    printf("%s", message);
    fflush(stdin);
    resp = scanf("%s", auxChar);
    if(resp == 1 && (strlen(auxChar)>lowLimit && strlen(auxChar) < hiLimit ) )
    {
        for(i= 0; i< strlen(auxChar); i ++)
        {
            auxChar[i] = tolower(auxChar[i]);
            if(auxChar[i] < 'a' || auxChar[i] >'z')
            {
                flagName = 0;
                break;
            }
        }
    }
    else
    {
        flagName = 0;
    }
    if(flagName)
    {
        auxChar[0] = toupper(auxChar[0]);
        strcpy(input, auxChar);
        return 0;
    }

    system("cls");
    printf("%s", eMessage);
    return -1;
}


/** \brief Solicita los datos al usuario
 *
 * \param puntero codigoProducto donde va a a guardar el codigo del producto solicitada
 * \param puntero importe donde va a a guardar el importe solicitada
 * \param puntero cantidad donde va a a guardar la cantidad del producto solicitada
 * \param puntero descripcion donde va a guardar la descripcion
 * \param int pedirCodigo si es 1 se le solicita el codigo, si es 0 no lo pide
 * \return
 *
 */
void pedirDatos(int* codigoProducto,float* importe, int* cantidad,char* descripcion, int pedirCodigo)
{
    int auxInt;
    int auxCodigo;
    float auxImporte;
    int auxCantidad;
    char auxDescripcion[50];
    do
    {
        auxInt = getString(auxDescripcion, "Ingrese su descripcion: ", "ERROR: Maximo 50 caracteres\n", 2, 50);
    }while(auxInt!=0);
    strcpy(descripcion, auxDescripcion);
    system("cls");
    if(pedirCodigo)
    {
        do
        {
            auxInt = getInt(&auxCodigo,"Ingrese el codigo del producto: ", "ERROR: solo se permiten numeros entre 1 y 1000\n", 1,1000);
        }while(auxInt!=0);
        *codigoProducto = auxCodigo;
        system("cls");
    }

    do
    {
        auxInt = getFloat(&auxImporte,"Ingrese el importe: ", "ERROR: solo se permiten numeros \n", 0,99999999);
    }while(auxInt!=0);
    *importe = auxImporte;
    system("cls");

    do
    {
        auxInt = getInt(&auxCantidad,"Ingrese la cantidad: ", "ERROR: solo se permiten numeros \n", 0,99999999);
    }while(auxInt!=0);
    *cantidad = auxCantidad;

}


/** \brief carga los datos pasados por parametro a un elemento del array
 *
 * \param edad la edad de tipo entera se pasa como parametro
 * \param dni el dni de tipo entera se pasa como parametro
 * \param nombre se para por parametro
 * \return una variable del tipo Epersona con los campos completos
 *
 */
eProductos cargarProducto(int codigoProducto, float importe, int cantidad,  char descripcion[])
{
    eProductos auxProductos;

    auxProductos.codigoProducto = codigoProducto;
    auxProductos.importe = importe;
    auxProductos.cantidad = cantidad;
    strcpy(auxProductos.descripcion, descripcion);
    auxProductos.isEmpty = 0;

    return auxProductos;
}
/** \brief solicita los datos al usuario y lo carga al producto
 *
 * \param puntero lista[] array de estructura donde se va a cargar el producto
 * \param int indice lugar donde va a cargar el producto
 * \return no devuelve nada
 *
 */

void agregarProducto(eProductos lista[], int indice)
{

    int codigoProducto;
    float importe;
    int cantidad;
    char descripcion[50];
    if(indice != -1)
        {
            pedirDatos(&codigoProducto, &importe, &cantidad, descripcion,1);
            lista[indice] = cargarProducto(codigoProducto, importe, cantidad, descripcion);
            printf("Producto Cargado!");
        }
        else
        {
            printf("No hay mas lugar\n");
        }
}


/**
 * Obtiene el indice que coincide con el codigo pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param codigo el codigo a ser buscado en el array.
 * @param cantidadItems la cantidad total de items
 * @return el indice en donde se encuentra el elemento que coincide con el parametro
   o [-1] si no existe.
 */
int buscarPorCodigo(eProductos lista[], int cantidadItems, int codigo)
{
    int i;
    int index = -1;
    for(i=0;i<cantidadItems; i++)
    {
        if(lista[i].codigoProducto == codigo)
        {
            index = i;
            break;
        }
    }
    return index;
}


/** \brief Indica si existe algun producto cargado
 *
 * \param puntero lista[] lugar donde va a iterar la funcion
 * \param int length tama�o maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun producto cargado o
 *         [0] si esta cargado con aunque sea un producto
 */
int isEmpty(eProductos lista[], int length)
{
    int i;
    int retorno = 1;
    for(i= 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


/** \brief Modifica un elemento existente de un array de estructuras
 *
 * \param puntero lista[] array de estructura donde busca el dato a modificar
 * \param int length tama�o maximo del array de estructura
 * \return
 *
 */

void modificar(eProductos lista[],int length)
{
    int indice;
    int codigoProducto, cantidad;
    float importe;
    char descripcion[50];
    int auxInt;
    auxInt = getInt(&codigoProducto, "Ingrese el codigo a buscar: ", "ERROR: solo se permiten numeros del 1 al 1000", 1, 1000);
    if(auxInt == 0)
    {
        indice = buscarPorCodigo(lista, length, codigoProducto);
        if(indice!= -1)
        {
                pedirDatos(&codigoProducto, &importe, &cantidad, descripcion, 0);
                lista[indice] = cargarProducto(codigoProducto, importe, cantidad, descripcion);
                printf("Producto modificado!");
        }
        else
        {
            printf("No existe ningun producto con ese codigo!\n");
        }
    }
}


/** \brief Modifica un elemento existente de un array de estructuras
 *
 * \param puntero lista[] array de estructura donde busca el dato a modificar
 * \param int length tama�o maximo del array de estructura
 * \return
 *
 */

void borrar(eProductos lista[], int length)
{
    int codigoProducto;
    int auxInt;
    int indice;
    auxInt = getInt(&codigoProducto, "Ingrese el codigo a borrar:", "ERROR: solo se permiten numeros del 1 al 1000", 1, 1000);
    if(auxInt== 0)
    {
        indice = buscarPorCodigo(lista, length, codigoProducto);
        if(indice != -1)
        {
            lista[indice].isEmpty = 1;
        }
        else
        {
            printf("No existe ningun producto con ese codigo\n!");
        }
    }
}


/** \brief buscar el importe mayor, o el importe menor segun el parametro
 *
 * \param eProducto array donde buscar el importe
 * \param int length tama�o maximo del array
 * \param int buscarMayor si es 1, busca el mayor, si es 0, el menor
 * \return devuelve el codigo del producto mayor
 *
 */

float buscarMayorMenor(eProductos lista[], int length, int buscarMayor)
{
    int i;
    int indice;
    int importe;
    int flagPrimera = 1;
    for(i = 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {

            if(buscarMayor == 1)
            {
                if(flagPrimera)
                {
                    importe = lista[i].importe;
                    indice = i;
                    flagPrimera = 0;
                }
                else
                {
                    if(lista[i].importe > importe)
                    {
                        importe = lista[i].importe;
                        indice = i;
                    }
                }
            }
            else if(buscarMayor == 0 )
            {
                if(flagPrimera)
                {
                    importe = lista[i].importe;
                    indice = i;
                    flagPrimera = 0;
                }
                else
                {
                    if(lista[i].importe < importe)
                    {
                        importe = lista[i].importe;
                        indice = i;
                    }
                }
            }
            else
            {
                printf("ERROR: no se puede obtener ni mayor ni menor");
            }
        }
    }

    return indice;
}


/** \brief calcula el total de los importes, el promedio y cuantos productos valen mas que el promedio
 *
 * \param eProductos lista[] donde busca los datos a ser calculados
 * \param puntero total, donde guarda el total de los importes
 * \param puntero promedio, donde guarda el promedio
 * \param puntero mayoresPromedio donde guarda cuantos son mayores que el promedio
 * \param length tama�o total del array donde buscar los datos
 * \return Nada guarda los datos en los punteros de los parametro
 *
 */

void calculosImportes(eProductos lista[],  float* total, float* promedio, int* mayoresPromedio, int length)
{
    float auxTotal = 0;
    float auxPromedio;
    int productos = 0;
    int auxMayores = 0;
    int i;

    for(i = 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            auxTotal = auxTotal + lista[i].importe;
            productos = productos + 1;
        }
    }
    auxPromedio = auxTotal / productos;
    *total = auxTotal;


    for(i= 0; i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            if(lista[i].importe > auxPromedio)
            {
                auxMayores = auxMayores +1;
            }
        }
    }
    *promedio = auxPromedio;
    *mayoresPromedio = auxMayores;
}

/** \brief Ordena por cantidad y en caso de igualdad, ordena por descripcion de producto
 *
 * \param eProductos lista[] array de la estructura eProductos
 * \param int length tama�o total del array
 * \return nada, solamente ordena el array
 *
 */

void ordenaPorCantidad(eProductos lista[], int length)
{
    int i,j;
    eProductos auxProducto;
    for(i=0;i<length-1; i++)
    {
        for(j=i+1;j<length;j++)
        {
            if(lista[i].cantidad>lista[j].cantidad)
            {
                auxProducto = lista[i];
                lista[i] = lista[j];
                lista[j] = auxProducto;
            }
            else if(lista[i].cantidad == lista[j].cantidad)
            {
                if(strcpy(lista[i].descripcion, lista[j].descripcion)< 0)
                {
                    auxProducto = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxProducto;

                }
            }
        }
    }
}

/** \brief muestra por pantalla un producto
 *
 * \param eProductos producto variable del tipo eProducto a ser mostrada
 * \return
 *
 */
void mostrarUno(eProductos producto)
{
    if(producto.isEmpty == 0)
    {
        printf("Codigo: %d\nDesctripcion: %s\nImporte: %.2f\nCantidad: %d\n", producto.codigoProducto, producto.descripcion, producto.importe, producto.cantidad);
    }
    else
    {
        printf("No existe ningun producto");
    }
}


/** \brief muestra una lista de todos los productos cargados en un array de estructura
 *
 * \param eProducto lista[] array de estructura a ser mostrado
 * \param int length tama�o maximo del array
 * \return
 *
 */
void mostrarProductos(eProductos lista[], int length)
{
    int i;
    for(i=0;i<length; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            mostrarUno(lista[i]);
        }
    }
}


