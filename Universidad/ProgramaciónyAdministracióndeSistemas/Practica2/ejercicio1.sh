#!/bin/bash
#1.Desarrollar un script en el que utilices los comandos grep y sed para formatear el fichero films.html que se proporciona. El fichero se encuentra en formato html, similar al que
#podrı́amos encontrar en una página como IMDB. El script deberá realizar las siguientes tareas:

    #1. Mostrar los datos de las pelı́culas en formato de texto plano similar al que se muestra en el ejemplo siguiente.
    #2. Mostrar el tı́tulo, el año y la valoración de las pelı́culas de los años 2000 (2000-2009).
    #3. Mostrar las pelı́culas en el mismo formato que se indicó en el punto 1 pero cambiando el formato del número de valoraciones para que muestre los miles como “k”. Por ejemplo, en
        #lugar de 658000, se deberá mostrar 658k.
    #4. Añadir un punto final a las lı́neas que no lo tengan.
    #5. Mostrar una versión resumida en la que la sinopsis se limitará a 300 caracteres, mostrando puntos suspensivos al final de la lı́nea.

echo -e "\n\n\t1) Mostrar los datos con el formato indicado:\n"
sed -e 's/<.2>/Titulo: /g' -e 's/(20/\n\t\tAño: 20/g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/<p>/Sinopsis: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<p id=.director.>/Director: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' ficherosPractica/films.html

echo -e "\n\n\t2) Mostrar solo titulo, año y valoracion de las peliculas de los 2000\n"
sed -e 's/<.2>/Titulo: /g' -e 's/(20/\n\t\tAño: 20/g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/<p>/Sinopsis: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<p id=.director.>/Director: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' ficherosPractica/films.html | grep -B 1 -A 1 '200[0-9]'

echo -e "\n\n\t3) Mostrar las valoraciones en formato 600k en vez de 600.000\n"
sed -e 's/<.2>/Titulo: /g' -e 's/(20/\n\t\tAño: 20/g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/<p>/Sinopsis: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<p id=.director.>/Director: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' -e 's/\([[:digit:]]\{3\}\)\([[:digit:]]\{3\}\)/\1\k/g' ficherosPractica/films.html

echo -e "\n\n\t4) Añadir punto al final si no lo tiene.\n"
sed -e 's/<.2>/Titulo: /g' -e 's/(20/\n\t\tAño: 20/g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/<p>/Sinopsis: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<p id=.director.>/Director: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' -e 's/$/\./' ficherosPractica/films.html

echo -e "\n\n\t5) Mostrar una versión resumida en la que la sinopsis se limita a 300 caracteres\n"
sed -e 's/<.2>/Titulo: /g' -e 's/(20/\n\t\tAño: 20/g' -e 's/<p id="rating">/Valoracion: /g' -e 's/<p id=.length.>/Duracion: /g' -e 's/<p>/Sinopsis: /g' -e 's/<p id=.genres.>/Generos: /g' -e 's/<p id=.director.>/Director: /g' -e 's/<. id="writers">/Guionistas: /g' -e 's/m<\/p>/ minutos/g' -e 's/<\/p>//g' -e '/<\/article>/d' -e '/<hr>/d' -e 's/<article>/\t==================================/g' -e 's/)<\/h2>/ /g' -e '/<\/body>/d' -e '/<\/html>/d' -e '/<!DOCTYPE html>/d' -e '/html/d' -e '/<head>/d' -e '/<title>Films<\/title>/d' -e '/<\/head>/d' -e '/<body>/d' -e '/<h1>Films<\/h1>/d' -e 's/[|]/, /g' -e 's/ratings/valoraciones/g' ficherosPractica/films.html | sed -e 's/^\(.\{318\}\).*$/\1.../'
