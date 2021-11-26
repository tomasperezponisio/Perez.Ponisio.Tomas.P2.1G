#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

typedef struct
{
    int id;
    char titulo[25];
    char genero[25];
    float rating;
}eMovie;

/** \brief contructor vacio de una estructura eMovie
 *
 * \return eMovie*
 *
 */
eMovie* pelicula_new();

/** \brief contructor parametrizado de una estructura eMovie
 *
 * \param idStr char*
 * \param tituloStr char*
 * \param generoStr char*
 * \param ratingStr char*
 * \return eMovie*
 *
 */
eMovie* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);

/** \brief destructor de una estructura eMovie
 *
 * \param pPelicula eMovie*
 * \return void
 *
 */
void pelicula_delete(eMovie* pPelicula);

/** \brief setter del campo id de la estructure eMovie
 *
 * \param this eMovie*
 * \param id int
 * \return int
 *
 */
int pelicula_setId(eMovie* this,int id);

/** \brief getter del campo id de la estructure eMovie, lo carga en la cariable que se le pasa por referencia
 *
 * \param this eMovie*
 * \param id int*
 * \return int
 *
 */
int pelicula_getId(eMovie* this,int* id);

/** \brief setter del campo titulo de la estructure eMovie
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int
 *
 */
int pelicula_setTitulo(eMovie* this,char* titulo);

/** \brief getter del campo titulo de la estructure eMovie, lo carga en la cariable que se le pasa por referencia
 *
 * \param this eMovie*
 * \param titulo char*
 * \return int
 *
 */
int pelicula_getTitulo(eMovie* this,char* titulo);

/** \brief setter del campo genero de la estructure eMovie
 *
 * \param this eMovie*
 * \param genero char*
 * \return int
 *
 */
int pelicula_setGenero(eMovie* this,char* genero);

/** \brief getter del campo genero de la estructure eMovie, lo carga en la cariable que se le pasa por referencia
 *
 * \param this eMovie*
 * \param genero char*
 * \return int
 *
 */
int pelicula_getGenero(eMovie* this,char* genero);

/** \brief setter del campo rating de la estructure eMovie
 *
 * \param this eMovie*
 * \param rating float
 * \return int
 *
 */
int pelicula_setRating(eMovie* this,float rating);

/** \brief getter del campo rating de la estructure eMovie, lo carga en la cariable que se le pasa por referencia
 *
 * \param this eMovie*
 * \param rating float*
 * \return int
 *
 */
int pelicula_getRating(eMovie* this,float* rating);

/** \brief es el menu del main
 *
 * \return int
 *
 */
int menu();

/** \brief muestra los campos de una estructura determinada
 *
 * \param pelicula eMovie*
 * \return int
 *
 */
int showPelicula(eMovie* pelicula);

/** \brief asigna un valor aleatorio float entre 1 y 10 al campo rating
 *
 * \param pelicula void*
 * \return int
 *
 */
int asignarRating(void* pelicula);

/** \brief asigna el campo genero aleatoriamente entre 4 opciones drama / comedia / accion / terror
 *
 * \param pelicula void*
 * \return int
 *
 */
int asignarGenero(void* pelicula);

/** \brief es la funcion que llama controller_filtrarGenero para filtrar por comedia
 *
 * \param pelicula void*
 * \return int
 *
 */
int filterComedia(void* pelicula);

/** \brief es la funcion que llama controller_filtrarGenero para filtrar por accion
 *
 * \param pelicula void*
 * \return int
 *
 */
int filterAccion(void* pelicula);

/** \brief es la funcion que llama controller_filtrarGenero para filtrar por drama
 *
 * \param pelicula void*
 * \return int
 *
 */
int filterDrama(void* pelicula);

/** \brief es la funcion que llama controller_filtrarGenero para filtrar por terror
 *
 * \param pelicula void*
 * \return int
 *
 */
int filterTerror(void* pelicula);

/** \brief es la funcion que llama controller_sortPeliculas para ordenar por genero y rating
 *
 * \param peliculaA void*
 * \param peliculaB void*
 * \return int
 *
 */
int compararGeneroRating( void* peliculaA, void* peliculaB );

#endif // PELICULA_H_INCLUDED
