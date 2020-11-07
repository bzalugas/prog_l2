#!/usr/bin/env bash

#use : add_signature "my_signature"

signature=$1

nb=1
file=NULL
end=0

while [ $end -eq 0 ];
do
    file=`find * -name '*.c' -print | head -$nb | tail +$nb`;
    if [ "$file" != "" ]
    then
        cat "$file" > temp.sig
        echo "$signature" > "$file"
        cat temp.sig >> "$file"
        (("nb = nb + 1"))
    else
        end=1
    fi
done
