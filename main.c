#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "LinkedList.h"
#include "pelicula.h"
#include "Controller.h"

int main()
{
    srand(time(NULL));
    char seguir = 's';
    char salir;

    LinkedList* listaPeliculas = ll_newLinkedList();

    do
    {
        switch ( menu() )
        {
        case 1:
            if ( !controller_loadFromText(listaPeliculas) )
            {
                printf("Error al cargar desde texto\n");
            }
            break;
        case 2:
            if ( !controller_ListPeliculas(listaPeliculas) )
            {
                printf("Error al mostrar lista\n");
            }
            break;
        case 3:
            if ( !controller_mapRating(listaPeliculas) )
            {
                printf("Error al asignar ratings\n");
            }
            break;
        case 4:
            if ( !controller_mapGenero(listaPeliculas) )
            {
                printf("Error al asignar genero\n");
            }
            break;
        case 5:
            if ( !controller_filtrarGenero(listaPeliculas) )
            {
                printf("Error al asignar genero\n");
            }
            break;
        case 6:
             if ( !controller_sortPeliculas(listaPeliculas) )
            {
                printf("Error al ordenar peliculas\n");
            }
            break;
        case 7:
            if ( !controller_saveAsText(listaPeliculas) )
            {
                printf("Error al guardar en modo texto\n");
            }
            break;
        case 8:
            printf("Esta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;
}
