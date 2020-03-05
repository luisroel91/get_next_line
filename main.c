#include "get_next_line.h"

int main()
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);	
}	
