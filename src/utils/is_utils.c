#include "ft_42sh.h"
#include <sys/stat.h>

int			is_dir(const char *name)
{
	struct stat	st;

	if (stat(name, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}

int			is_file(const char *path, int flag)
{
	struct stat	st;

	if (lstat(path, &st) == -1)
		return (0);
	if (S_ISREG(st.st_mode))
	{
		if (flag == O_RDONLY)
			return (S_IRUSR & st.st_mode);
		if (flag == O_WRONLY)
			return (S_IWUSR & st.st_mode);
		if (flag == O_RDWR)
			return (S_IWUSR &st.st_mode && S_IRUSR & st.st_mode);
	}
	return (0);
}
