#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	char	*line;

	int fd1 = open("file11.txt", O_RDONLY); 
	int fd2 = open("file12.txt", O_RDONLY); 

	line = get_next_line(fd1); 
	printf("%s", line);
	free(line);
	line = get_next_line(fd2); 
	printf("%s", line);
	free(line);
	line = get_next_line(fd1); 
	printf("%s", line);
	free(line);
	line = get_next_line(fd2); 
	printf("%s", line);
	free(line);
	
	close(fd1);
	close(fd2);
	return (0);
}
