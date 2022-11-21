#!/bin/bash
echo $PS1
s="\h:~(hola, son las \t)&"
PROMPT_COMMAND="PS1='$s';unset PROMPT_COMMAND" bash
exit
#s="$s\\u";;
#s="$s\\u";;
#s="$s\\u";;
#s="$s\\u";;
#s="$s\\u";;
