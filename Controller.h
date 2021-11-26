/** \brief carga los datos que le llegan del parser en una linkedlist
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayPelicula);

/** \brief pide un nombre de archivo para pasarselo al parser
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_saveAsText(LinkedList* pArrayPelicula);

/** \brief muestra la lista de peliculas
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_ListPeliculas(LinkedList* pArrayPelicula);

/** \brief asigna valores de rating (random entre 1 y 10)
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_mapRating(LinkedList* pArrayPelicula);

/** \brief asigna el genero aleatoriamente
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_mapGenero(LinkedList* pArrayPelicula);

/** \brief filtra las peliculas por el genero seleccionado y los guarda en un csv
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_filtrarGenero(LinkedList* pArrayPelicula);

/** \brief ordena las peliculas por genero y rating
 *
 * \param pArrayPelicula LinkedList*
 * \return int
 *
 */
int controller_sortPeliculas(LinkedList* pArrayPelicula);







