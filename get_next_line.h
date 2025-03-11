#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# define BUFFER_SIZE 12

#include <unistd.h> // for the read function
#include <stdlib.h> // for malloc

char	*gnl_strchr(char *s, int c);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);

#endif // GET_NEXT_LINE_H
