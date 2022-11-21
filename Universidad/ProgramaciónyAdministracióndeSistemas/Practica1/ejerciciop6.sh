#!/bin/bash
if [ $# -ne 1 ];
then
	echo "ERROR"
	exit 1
fi
cat $1 | while IFS= read -r line
do
  echo "$(resolveip -s "$line")		$line" 
done<<<$(cat "$1")

#Otro método 
#cat $1 | while read line; do
#ip=$(resolveip -s $line)
#printf "%-30s%-30%s\n" $ip $line
#done | sort -t . -kl,ln -k2,2n -k3,3n -k4,4n
