#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	line = NULL;
	int	fd = open("test.txt", O_RDONLY);
	int ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf("line: '%s' | ret: %d\n", line, ret);
	}
	close(fd);
}
