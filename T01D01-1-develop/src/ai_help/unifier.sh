#!/bin/bash

FILES=key/*.key
KEY=0

for file in $FILES
do
    if [[ $file =~ \.key$ ]]
    then
        tmp=$(< $file)
        KEY=$(($KEY + $tmp))
    fi
done

if [ $KEY == 0 ]
then
    echo "Error."
else
    echo "Ok."
    echo $(($KEY*2)) > main.key
fi
