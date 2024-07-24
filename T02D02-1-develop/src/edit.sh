#!/bin/bash

echo "Путь к файлу: "
read path
echo "Строка для замены: "
read string1
echo "Замена на: "
read string2

if [ -f "../$path" ]; then
	# edit path
	sed -i '' -e "s/$string1/$string2/g" "../$path"

	FILESIZE=$(wc -c ../$path | awk '{print $1}')
	TIME=$(date '+%Y-%m-%d %H:%M')
	SHA=$(shasum -a 256 ../$path | awk '{print $1}')

	# edit files.log
	echo "$path - $FILESIZE - $TIME - $SHA - sha256" >> ../src/files.log
else
	echo "Файл не найден"
fi
