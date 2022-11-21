#!/bin/bash
OLDIFS=$IFS
IFS=$'\n'
for x in $(who)
do
	CONTROL="$(mktemp)"	
	echo $x > $CONTROL
	user=$(grep -E -o '^[[:alnum:]]*' $CONTROL)
	hora=$(grep -E -o '[[:digit:]]*-[[:digit:]]*-[[:digit:]]* [[:digit:]]*:[[:digit:]]*' $CONTROL)
	sesion=$(date -d "$hora" +%s)
	rm $CONTROL
	actual=$(date +%s)
	let diferencia=$actual-$sesion
	date -ud @$diferencia +"El usuario $user lleva conectado desde las $hora y lleva ausente "
done
IFS=$OLDIFS

