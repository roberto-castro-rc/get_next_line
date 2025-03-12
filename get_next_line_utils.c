#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	return (NULL);
}

char	*gnl_strdup(char *s1)
{
	char	*copy_str;
	int		i;

	if (!s1)
		s1 = "";
	copy_str = (char *)malloc(gnl_strlen(s1) + 1);
	if (!copy_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy_str[i] = s1[i];
		i++;
	}
	copy_str[i] = '\0';
	return (copy_str);
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
	free(s1);
	newstr[i + j] = '\0';
	return (newstr);
}
