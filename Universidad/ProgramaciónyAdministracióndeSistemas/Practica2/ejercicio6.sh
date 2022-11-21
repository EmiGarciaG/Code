#!/bin/bash
df -h | sed -r -n -e '2,$s/^([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)[ ]+([^ ]+)$/El sistema de ficheros \1, montado en \6, tiene un tamaño de \2, de los cuales se están usando \3, que representan un \5 del total. Quedan libres \2-\3/p'

#df -h | grep --color -E '^[a-Z0-9/\:]+ +[0-9]+ +[0-9]+ +[0-9]+ +[0-9]+% +[0-9a-Z/]+$'

#df -h | sed -r -n -e '2,$s/(^[a-Z0-9/\:]+) +([0-9]+) +([0-9]+) +([0-9]+) +([0-9]+%) +([0-9a-Z/]+)$/El fichero de bloques \1, montado en \6, tiene usados \3 bloques de un total de \2 (porcentaje de \5)./p'
