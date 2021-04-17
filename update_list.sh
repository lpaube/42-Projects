#!/bin/zsh

function add_to_list() {
	file=${file%.*}
	sed -i '' "s/- \[ ] $file$/- \[x] $file/g" README.md
}

while read line;
do
	if [[ "$line" == *"- [x]"* ]]
	then
		state=0
		for file in *.c;
		do
			file_from_list=$(grep -oE "[^ ]+$" <<< "$line")
			file=${file%.*}
			if [ $file_from_list == $file ]
			then
				state=1
			fi
		done
		if [ $state == 0 ]
		then
			sed -i '' "s/- \[x]/- \[ ]/g" README.md
		fi
	fi
done < README.md

for file in *.c;
do
	add_to_list;
done
