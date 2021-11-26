#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pelicula.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_peliculaFromText(FILE* pFile , LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    int cant;

    char id[50];
    char titulo[50];
    char genero[50];
    char rating[50];

    eMovie* auxPelicula;

    if (pFile != NULL && pArrayPelicula != NULL  )
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, genero, rating);
        do
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,titulo,genero, rating);
            if (cant < 4)
            {
                break;
            }

            auxPelicula = pelicula_newParametros( id, titulo, genero, rating);
            if (auxPelicula != NULL)
            {
                ll_add( pArrayPelicula, auxPelicula );
                todoOk = 1;
                auxPelicula = NULL;
            }
        }
        while (!feof(pFile));
    }
    return todoOk;

}
