cd ai_help
sh keygen.sh
nano unifier.sh

#!/bin/bash

FILES=key/*
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
