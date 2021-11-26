#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "parser.h"
#include "BibliotecaPersonal.h"
#include "Controller.h"

int controller_loadFromText(LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    FILE* pFile;
    char path[25];

    if ( pArrayPelicula != NULL )
    {
        system("cls");
        printf("****** Cargar los datos de las peliculas ******\n");
        printf("Ingrese el nombre del archivo (movies.csv): ");
        scanf("%s", path);
        while ( strcmp(path, "movies.csv") != 0 )
        {
            printf("**ERROR** Ingrese el nombre del archivo (movies.csv): ");
            scanf("%s", path);
        }

        pFile = fopen( path, "r");
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if ( parser_peliculaFromText( pFile, pArrayPelicula ) )
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

int controller_saveAsText(LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    FILE* pFile;

    char path[25];
    int id;
    char titulo[50];
    char genero[50];
    float rating;

    eMovie* auxPelicula;

    if ( path != NULL && pArrayPelicula != NULL )
    {
        system("cls");
        printf("Ingrese el nombre del archivo a guardar (SOLO EL NOMBRE SIN LA EXTENSION): ");
        scanf("%s", path);

        strcat(path, ".csv");

        pFile = fopen(path, "w"); // abro el archivo
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");
        }

        fprintf( pFile, "id,titulo,genero,rating\n" );

        for (int i = 0; i < ll_len(pArrayPelicula); i++)
        {
            auxPelicula = ll_get(pArrayPelicula, i);
            if ( pelicula_getId( auxPelicula, &id ) &&
                    pelicula_getTitulo( auxPelicula, titulo ) &&
                    pelicula_getGenero( auxPelicula, genero) &&
                    pelicula_getRating( auxPelicula, &rating)
               )
            {
                fprintf(pFile, "%d,%s,%s,%.1f\n", id, titulo, genero, rating );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

int controller_ListPeliculas(LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    eMovie* auxPelicula;
    if (pArrayPelicula != NULL)
    {
        system("cls");
        printf("*** Listar Peliculas\n\n");

        printf("Id     Titulo                                                     Genero            Rating\n");
        for (int i = 0; i < ll_len(pArrayPelicula); i++)
        {
            auxPelicula = (eMovie*) ll_get( pArrayPelicula, i );
            showPelicula(auxPelicula);
        }
        todoOk = 1;
    }
    return todoOk;
}

int controller_mapRating(LinkedList* pArrayPelicula)
{
    int todoOk = 0;

    pArrayPelicula = ll_map(pArrayPelicula, asignarRating);

    if ( pArrayPelicula != NULL  )
    {
        controller_ListPeliculas(pArrayPelicula);

        todoOk = 1;
    }
    return todoOk;
}

int controller_mapGenero(LinkedList* pArrayPelicula)
{
    int todoOk = 0;

    pArrayPelicula = ll_map(pArrayPelicula, asignarGenero);

    if ( pArrayPelicula != NULL  )
    {
        controller_ListPeliculas(pArrayPelicula);

        todoOk = 1;
    }
    return todoOk;
}

int controller_filtrarGenero(LinkedList* pArrayPelicula)
{
    int todoOk = 0;
    int opcion;
    //char nombreArchivo[50];

    system("cls");
    printf("*** Filtrado por genero:\n");
    printf(" 1 - drama\n");
    printf(" 2 - comedia\n");
    printf(" 3 - accion\n");
    printf(" 4 - terror\n");

    validarEntero(&opcion, "Ingrese el genero a filtrar (1-2-3-4): ", " ***ERROR*** ", 1,4,25);

    switch (opcion)
    {
    case 1:
        pArrayPelicula = ll_filter(pArrayPelicula, filterDrama);
        //strcpy(nombreArchivo, "moviesDrama.csv");
        break;
    case 2:
        pArrayPelicula = ll_filter(pArrayPelicula, filterComedia);
        //strcpy(nombreArchivo, "moviesComedia.csv");
        break;
    case 3:
        pArrayPelicula = ll_filter(pArrayPelicula, filterAccion);
        //strcpy(nombreArchivo, "moviesAccion.csv");
        break;
    case 4:
        pArrayPelicula = ll_filter(pArrayPelicula, filterTerror);
        //strcpy(nombreArchivo, "moviesTerror.csv");
        break;
    }

    if ( pArrayPelicula != NULL  )
    {
        controller_ListPeliculas(pArrayPelicula);
        system("pause");
        controller_saveAsText(pArrayPelicula);
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortPeliculas(LinkedList* pArrayPelicula)
{
    int todoOk = 0;

    if ( pArrayPelicula != NULL )
    {
        todoOk = 1;
        system("cls");
        printf("*** Ordenar por genero y rating descendente\n");
        ll_sort( pArrayPelicula, compararGeneroRating, 1 );
        controller_ListPeliculas(pArrayPelicula);
    }
    return todoOk;

}
