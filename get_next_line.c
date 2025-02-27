#include "get_next_line.h"

char *ft_strrchr(const char *s, int c);
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

	if(ft_strrchr(buf, '\n'))
	{
		temp = ft_strrchr(buf, '\n');

		buf[temp + 1] = '\0';
		return (buf);
	}

	return NULL;
}
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while(s[count] != '\0')
	{
		count++;
	}

	return count;
}

char *ft_strrchr(const char *s, int c)
{
	int i;

 i = ft_strlen(s);
 if ((unsigned char)c == '\0')
 {
	 return ((char *)(s + i));
 }
 while (i >= 0)
 {
	 if (s[i] == (unsigned char)c)
	 {
		 return ((char *)(s + i));
	 }
	 i--;
 }

 return NULL;
}


char *get_line(int fd)
{
	// Your implementation here
	return NULL;
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{

	int fd = open("test.txt", O_RDONLY);
	char *line;
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}