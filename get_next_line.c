#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(const char *s1);
char *extract_line(char *backup);
char	*get_next_line(int fd)
{
	static char *backup;
	char *buf;
	char *line;
	int bytes_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
	{
		return NULL;
	}

	while (1)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if(!buf)
			return NULL;
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
		if(bytes_read == 0)
		{
			return backup;
		}
		line = extract_line(backup);
		if(gnl_strchr(line, '\n'))
		{
			printf("found newline\n");
			return line;
		}

	}
	return backup;
}
char *clean_backup(char *backup)
{
	int i;
	char *new_backup;

	if (!backup)
	{
		return NULL;
	}
	while(backup[i] != '\0' && backup[i] != '\n')
	{
		i++;
	}
	
}
char *extract_line(char *backup)
{
	int i;
	int newline;
	char *line;

	if(!backup || !backup[0])
	{
		return NULL;
	}
	newline = 0;
	i = 0;
	while(backup[i] != '\0')
	{
		if (backup[i] == '\n')
		{
			newline = 1;
			break;
		}
		i++;
	}
	/*
	if(backup[i] == '\n)
	{
		i += 1;
	}
	*/
	line = (char *)malloc(sizeof(char) * (i + newline + 1));
	if(!line)
	{
		return NULL;
	}
	i = 0;
	while (backup[i] != '\0' && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	printf("%s; %c", backup, backup[i]);
	if (backup[i] == '\n')
	{
		line[i] = '\n';
	}
	line[++i] = '\0';
	return line;
}


int	gnl_strlen(const char *s)
{
	int i;

	i = 0;
	if(s)
	{
		while(s[i] != '\0')
		{
			i++;
		}
	}
	return i;
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1)
		s1 = gnl_strdup("");
	if (!s2)
		return (NULL);
	newstr = (char *)malloc((gnl_strlen(s1) + gnl_strlen(s2)) + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
char	*gnl_strdup(const char *s1)
{
	char	*copy_str;
	size_t	i;

	if (!s1)
		s1 = "";
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


int	main(void)
{

	int fd = open("test.txt", O_RDONLY);

	printf("print main \n%s\n", get_next_line(fd));
	printf("print 2 main \n%s\n", get_next_line(fd));
	printf("print 3 main \n%s\n", get_next_line(fd));
	close(fd);
	return (0);
}

