
i="0"

while [ $i -lt 200 ]
do
	gcc -D BUFFER_SIZE=42 -I../get_next_line test.c ../get_next_line/*.c
	./a.out > /dev/null
	i=$[$i+1]
done
