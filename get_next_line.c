#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *extract_line(char *backup);
char *clean_backup(char *backup);
char	*get_next_line(int fd)
{
	static char *backup;
	char *reading;
	char *line;
	int bytes_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	reading = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!reading)
		return NULL;
	bytes_read = 1;
	while (!gnl_strchr(backup, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, reading, BUFFER_SIZE);
		if(bytes_read == -1)
		{
			free(reading);
			return NULL;
		}
		reading[bytes_read] = '\0';
		backup = gnl_strjoin(backup, reading);
		if(!backup)
			return NULL;
	}
	line = extract_line(backup);
	backup = clean_backup(backup);
	free(reading);
	return line;
}
char *clean_backup(char *backup)
{
	int i;
	char *new_backup;

	if (!backup)
	{
		return NULL;
	}
	i = 0;
	while(backup[i] != '\0' && backup[i] != '\n')
	{
		i++;
	}
	if(backup[i] == '\0')
	{
		free(backup);
		return NULL;
	}
	new_backup = gnl_strdup(&backup[i + 1]);
	free(backup);
	return new_backup;
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
	if(backup[i] == '\n')
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
	if (backup[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return line;
}

// int	main(void)
// {
// 	char *line;
// 	int fd = open("test.txt", O_RDONLY);

// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("print main \n%s", line);
// 	}

// 	printf("print 1 main \n%s", get_next_line(fd));

// 	close(fd);
// 	return (0);
// }

