#include "ft_42sh.h"
#define		DIRPATH_SIZE(x)		(ft_strrchr(x, '/') - x + 1)
#define		FILENAME_SIZE(x)	(ft_strchr(x, '\0') - ft_strrchr(x, '/'))

/*
 **	The buffer size for these functions must be >= PATH_MAX.
*/

char		*get_dirpath(char *path, char *buff)
{
	if (!*path)
		return (NULL);
	if (ft_strchr(path, '/'))
	{
		ft_strlcpy(buff, path, DIRPATH_SIZE(path) + 1);
		return (buff);
	}
	else
		return (NULL);
}

char		*get_filename(char *path, char *buff)
{
	if (!*path)
		return (NULL);
	if (ft_strchr(path, '/'))
		ft_strcpy(buff, path + DIRPATH_SIZE(path));
	else
		ft_strcpy(buff, path);
	return (buff);
}

size_t		get_dirpath_length(char *path)
{
	if (ft_strchr(path, '/'))
		return (DIRPATH_SIZE(path));
	return (0);
}

size_t		get_filename_length(char *path)
{
	if (ft_strchr(path, '/'))
		return (FILENAME_SIZE(path) - 1);
	return (ft_strlen(path));
}

char		*unscape_space(char *path)
{
	char	*readptr;
	char	*ret;

	readptr = path;
	ret = path;
	while (*readptr)
	{
		if (*readptr == '\\' && *(readptr + 1) == ' ')
			readptr++;
		*path++ = *readptr++;
	}
	*path = 0;
	return (ret);
}
