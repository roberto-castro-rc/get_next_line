#include "get_next_line.h"

char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*gnl_strdup(const char *s1);
char	*get_next_line(int fd)
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
	while (1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if(bytes_read == -1)
		{
			free(buf);
			return NULL;
		}
		buf[bytes_read] = '\0';
		backup = gnl_strjoin(backup, buf);
		free(buf);
		if(!backup)
		{
			return NULL;
		}
		if(gnl_strchr(backup, '\n'))
		{
			return (backup);
		}

	}
	return buf;
}
int	gnl_strlen(const char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return i;
}
char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	size_t	i;

	if (!s1)
	{
		s1 = gnl_strdup("");
	}

	if (!s2)
		return (NULL);
	i = gnl_strlen(s1) + gnl_strlen(s2);
	newstr = (char *)malloc(i * sizeof(char) + 1);
	if (!newstr)
		return (NULL);
	newstr[i] = '\0';
	while (*s1 != '\0')
		*newstr++ = *s1++;
	while (*s2 != '\0')
		*newstr++ = *s2++;
	return (newstr - i);
}
char	*gnl_strdup(const char *s1)
{
	char	*copy_str;
	size_t	i;

	copy_str = (char *)malloc(gnl_strlen(s1) + 1);
	if (!copy_str)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		copy_str[i] = s1[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
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
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}

