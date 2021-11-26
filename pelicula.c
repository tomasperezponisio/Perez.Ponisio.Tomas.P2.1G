#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "pelicula.h"

// CONSTRUCTORES

eMovie* pelicula_new()
{
    eMovie* nuevaPelicula = (eMovie*) malloc(sizeof(eMovie));
    if (nuevaPelicula != NULL)
    {
        nuevaPelicula->id = 0;
        strcpy(nuevaPelicula->titulo, "");
        strcpy(nuevaPelicula->genero, "");
        nuevaPelicula->rating = 0;
    }
    return nuevaPelicula;
}

eMovie* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr)
{
    eMovie* nuevaPelicula = pelicula_new();
    if (nuevaPelicula != NULL)
    {
        pelicula_setId(nuevaPelicula, atoi(idStr));
//        nuevaPelicula->id = atoi(idStr);
        pelicula_setTitulo(nuevaPelicula, tituloStr);
//        strcpy(nuevaPelicula->titulo, tituloStr);
        pelicula_setGenero(nuevaPelicula, generoStr);
//        strcpy(nuevaPelicula->genero, generoStr);
        pelicula_setRating(nuevaPelicula, atof(ratingStr));
//        nuevaPelicula->rating = atof(ratingStr);

    }
    return nuevaPelicula;
}

// DESTRUCTOR

void pelicula_delete(eMovie* pPelicula)
{
    if (pPelicula != NULL)
    {
        free(pPelicula);
    }
}

// SETTERS Y GETTERS

int pelicula_setId(eMovie* this,int id)
{
    int todoOk = 0;
    if (this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getId(eMovie* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setTitulo(eMovie* this,char* titulo)
{
    int todoOk = 0;
    if (this != NULL && titulo != NULL && strlen(titulo) > 0 && strlen(titulo) < 128)
    {
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getTitulo(eMovie* this,char* titulo)
{
    int todoOk = 0;
    if (this != NULL && titulo != NULL )
    {
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setGenero(eMovie* this,char* genero)
{
    int todoOk = 0;
    if (this != NULL && genero != NULL && strlen(genero) > 0 && strlen(genero) < 128)
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getGenero(eMovie* this,char* genero)
{
    int todoOk = 0;
    if (this != NULL && genero != NULL )
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setRating(eMovie* this,float rating)
{
    int todoOk = 0;
    if (this != NULL && rating > 0)
    {
        this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getRating(eMovie* this,float* rating)
{
    int todoOk = 0;
    if (this != NULL && rating != NULL)
    {
        *rating = this->rating;
        todoOk = 1;
    }
    return todoOk;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** Peliculas ***\n");
    printf("  1- Cargar los datos de las peliculas\n");
    printf("  2- Imprimir lista\n");
    printf("  3- Asignar rating\n");
    printf("  4- Asignar genero\n");
    printf("  5- Filtrar por genero\n");
    printf("  6- Ordenar peliculas\n");
    printf("  7- Guardar los datos de los peliculas\n");
    printf("  8- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

int showPelicula(eMovie* pelicula)
{
    int todoOk = 0;

    int id;
    char titulo[50];
    char genero[50];
    float rating = 0;

    if (pelicula != NULL)
    {
        todoOk = 1;
        if ( pelicula_getId( pelicula, &id ) &&
                pelicula_getTitulo( pelicula, titulo ) &&
                pelicula_getGenero( pelicula, genero ) &&
                pelicula_getRating( pelicula, &rating)
           )
        {
            printf ("%-4d   %-35s                        %-15s    %-4.1f\n", id, titulo, genero, rating);
            todoOk = 1;
        }
    }
    return todoOk;
}

int asignarRating(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;
    float rating;
    int min = 10;
    int max = 100;

    if (pelicula != NULL)
    {
        todoOk = 1;
        aux = (eMovie*) pelicula;
        rating = (float) (rand() % ( max - min + 1)  + min)  / 10 ;
        pelicula_setRating(aux, rating);
    }
    return todoOk;
}

int asignarGenero(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;
    int opcion;
    int min = 1;
    int max = 4;

    if (pelicula != NULL)
    {
        todoOk = 1;
        aux = (eMovie*) pelicula;
        opcion = rand() % ( max - min + 1)  + min;
        switch (opcion)
        {
        case 1:
            pelicula_setGenero(aux, "drama");
            break;
        case 2:
            pelicula_setGenero(aux, "comedia");
            break;
        case 3:
            pelicula_setGenero(aux, "accion");
            break;
        case 4:
            pelicula_setGenero(aux, "terror");
            break;
        }
    }
    return todoOk;
}

int filterDrama(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;

    if ( pelicula!= NULL)
    {
        aux = (eMovie*) pelicula;
        if ( strcmp( aux->genero, "drama"  ) == 0  )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterComedia(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;

    if ( pelicula!= NULL)
    {
        aux = (eMovie*) pelicula;
        if ( strcmp( aux->genero, "comedia"  ) == 0  )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterAccion(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;

    if ( pelicula!= NULL)
    {
        aux = (eMovie*) pelicula;
        if ( strcmp( aux->genero, "accion"  ) == 0  )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


int filterTerror(void* pelicula)
{
    int todoOk = 0;
    eMovie* aux = NULL;

    if ( pelicula!= NULL)
    {
        aux = (eMovie*) pelicula;
        if ( strcmp( aux->genero, "terror"  ) == 0  )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int compararGeneroRating( void* peliculaA, void* peliculaB )
{
    int todoOk = 0;

    if(  ( strcmp( ((eMovie*)peliculaA)->genero,  ((eMovie*)peliculaB)->genero )  > 0 ) ||
       ( ( strcmp( ((eMovie*)peliculaA)->genero,  ((eMovie*)peliculaB)->genero )  == 0 ) &&
                   ((eMovie*)peliculaA)->rating < ((eMovie*)peliculaB)->rating )
           )
    {
        todoOk = 1;
    }
    if(  ( strcmp( ((eMovie*)peliculaA)->genero,  ((eMovie*)peliculaB)->genero )  < 0 ) ||
       ( ( strcmp( ((eMovie*)peliculaA)->genero,  ((eMovie*)peliculaB)->genero )  == 0 ) &&
                   ((eMovie*)peliculaA)->rating > ((eMovie*)peliculaB)->rating )
          )
    {
        todoOk = -1;
    }
    return todoOk;
}
