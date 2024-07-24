#!/bin/bash

echo "Путь к журналу: "
read path
if [ -f "../$path" ]; then
	COUNT_OF_LINES=$(wc -l ../$path | awk '{print $1}')
	
	#declare -a files
	#declare -a hashes
	
	#while read line; do
	#	files+=$(awk '{print $1}' $line)
	#	hashes+=$(awk '{print $8}' $line)
	#done < ../$path

	#for i in "${files[@]}"; do echo $i; done
	
	UNIQ_FILES=$(awk '{print $1}' ../$path | sort -u | wc -l)
	UNIQ_HASH=$(awk '{print $8}' ../$path | sort -u | wc -l)
	
	declare -i COUNT_UNIQ_HASH=$UNIQ_HASH-$UNIQ_FILES
	declare -i COUNT_UNIQ_FILES=$UNIQ_FILES+0

	echo "$COUNT_OF_LINES $COUNT_UNIQ_FILES $COUNT_UNIQ_HASH"
else
	echo "Журнал не найден"
fi
