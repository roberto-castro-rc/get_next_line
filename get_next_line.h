#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <unistd.h> // for the read function
#include <stdlib.h> // for malloc

int		gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_strdup(char *s1);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *backup);
char	*clean_backup(char *backup);
#endif // GET_NEXT_LINE_H
