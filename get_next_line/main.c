#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("file11.txt", O_RDONLY);
	printf("%d\n", fd1);
	fd2 = open("file12.txt", O_RDONLY);
	printf("%d\n", fd2);
	fd1 = open("aya.txt", O_RDONLY);
	printf("%d\n", fd1);

	if (fd1 == -1)
	{
		perror("Error opening file1.txt");
		return (1);
	}
	if (fd2 == -1)
	{
		perror("Error opening file1.txt");
		return (1);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd2);
	return (0);
}
