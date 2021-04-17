#!/bin/zsh

main=0
sup=0

function add_to_list() {
	file=${file%.*}
	state=0
	while read line
	do
		if grep -q "$file" <<< "$line"
		then
			break
		fi
		if grep -q "Supporting" <<< "$line"
		then
			state=1
		fi
	done < README.md
	if [ $state == 1 ]
	then
		((sup++))
	elif [ $state == 0 ]
	then
		((main++))
	fi
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

sed -i '' "s|(\d+ / 26)|($main / 26)|" README.md
sed -i '' "s|(\d+ / 23)|($sup / 23)|" README.md
