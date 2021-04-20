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
	if [ $state = 1 ]
	then
		((sup++))
	elif [ $state = 0 ]
	then
		((main++))
	fi
	sed -i '' "s/- \[ ] $file$/- \[x] $file/g" README.md
}

while read line;
do
	if [[ "$line" = *"- [x]"* ]]
	then
		state=0
		for file in *.c;
		do
			file_from_list=$(grep -oE "[^ ]+$" <<< "$line")
			file=${file%.*}
			if [[ $file_from_list == $file ]]
			then
				state=1
			fi
		done
		if [[ $state = 0 ]]
		then
			sed -i '' "s/- \[x]/- \[ ]/g" README.md
		fi
	fi
done < README.md


for file in *.c;
do
	add_to_list;
done

sed -E -i '' "s|\([0-9]+ \/ 26\)|($main \/ 26)|g" README.md
sed -E -i '' "s|\([0-9]+ \/ 23\)|($sup \/ 23)|g" README.md

echo "\033[0;36m-- README.md is now up to date\n"
echo " --------- Libft completion status --------- "

((mainres= $main * 10 / 26))
((supres= $sup * 10 / 23))
printf "| \033[0m-- (Libc    |"
for ((done=0; done <= $mainres; done++));
do
	printf "\033[0;32m▇"
done
for ((remain=$mainres; remain < 10; remain++));
do
	printf " "
done

if (( $main < 10 ))
then
	numain=0$main
else
	numain=$main
fi
if [[ $mainres -eq 0 ]]
then
	printf "\033[0m|  %i%%)    [$numain/26] \033[0;36m|\n| \033[0m-- (Support |" "$((mainres * 10))"
elif (( $mainres < 10 ))
then
	printf "\033[0m| %i%%)    [$numain/26] \033[0;36m|\n| \033[0m-- (Support |" "$((mainres * 10))"
else
	printf "\033[0m|%i%%)    [$numain/26] \033[0;36m|\n| \033[0m-- (Support |" "$((mainres * 10))"
fi


for ((done=0; done <= $supres; done++));
do
	printf "\033[0;32m▇"
done
for ((remain=$supres; remain < 10; remain++));
do
	printf " "
done

if (( $sup < 10 ))
then
	nusup=0$sup
else
	nusup=$sup
fi

if [[ $supres -eq 0 ]]
then
	printf "\033[0m|  %i%%)    [$nusup/23] \033[0;36m|\n" "$((supres*10))"
elif (( $supres < 10 ))
then
	printf "\033[0m| %i%%)    [$nusup/23] \033[0;36m|\n" "$((supres*10))"
else
	printf "\033[0m|%i%%)    [$nusup/23] \033[0;36m|\n" "$((supres*10))"
fi
echo "\033[0;36m ------------------------------------------- "
