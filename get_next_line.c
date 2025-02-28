#include "get_next_line.h"

char *gnl_strchr(char *s, int c);
char *get_next_line(int fd)
{
	static char *backup;
	char *buf;
	int i;
	int bytes_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
	{
		return NULL;
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buf)
	{
		return NULL;
	}

	bytes_read = read(fd, buf, BUFFER_SIZE);

	if(gnl_strchr(buf, '\n'))
	{
		return (buf);
	}

	return NULL;
}

char	*gnl_strchr(char *s, int c)
{	int i;
	if(!s)
	{
		return NULL;
	}
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	return NULL;
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{

	int fd = open("test.txt", O_RDONLY);
	char *line;
	printf("%s\n", NULL);

	close(fd);
	return (0);
}

