#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		count;

	if (argc != 2)
	{
		printf("usage: ./program <file>\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error: cannot open file\n");
		return (1);
	}
	count = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("line %d: %s", count, line);
		free(line);
		count++;
		line = get_next_line(fd);
	}
	printf("\ntotal: %d lines\n", count - 1);
	close(fd);
	return (0);
}
