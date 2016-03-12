#include "ft_42sh.h"
#include <sys/stat.h>

int			is_dir(const char *name)
{
	struct stat	st;

	if (lstat(name, &st) == -1)
		return (0);
	return (S_ISDIR(st.st_mode));
}
