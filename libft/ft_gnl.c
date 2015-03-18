/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 16:41:28 by fdaudre-          #+#    #+#             */
/*   Updated: 2015/03/16 17:07:11 by fdaudre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define GNL_REM1		remain[fd].b[remain[fd].turn]
#define GNL_REM2		remain[fd].b[!remain[fd].turn]

static int				rec_gnl(int const fd, char **line, t_gnl *remain,
							int index)
{
	static char			buff[FT_GNL_BUFSIZE + 1];
	char				*endl;
	int					ret;
	int					exitval;

	if ((ret = read(fd, buff, FT_GNL_BUFSIZE)) < 0)
		return (-1);
	buff[ret] = '\0';
	if (((endl = ft_strchr(buff, '\n')) == NULL) && ret)
	{
		exitval = rec_gnl(fd, line, remain, index + ret);
		ft_memcpy(*line + index, buff, ret);
		return (exitval);
	}
	exitval = (endl == NULL ? 0 : endl - buff);
	*line = (char *)malloc((index + exitval + 1) * sizeof(char));
	ft_strncpy(*line + index, buff, exitval);
	(*line)[index + exitval] = '\0';
	ft_strcpy(GNL_REM2, endl == NULL ? "" : endl + 1);
	return (ret + index ? 1 : 0);
}

static inline int		init_gnl(int const fd, char **line, t_gnl **remain)
{
	int					i;

	if ((fd < 0) || (fd > FT_GNL_MAXFD - 1))
		return (-1);
	if (*line != NULL)
		ft_memdel((void **)line);
	if (*remain != NULL)
		return (0);
	*remain = (t_gnl *)malloc(sizeof(t_gnl) * FT_GNL_MAXFD);
	i = -1;
	while (++i < FT_GNL_MAXFD)
	{
		(*remain)[i].turn = 0;
		(*remain)[i].b[0][0] = '\0';
		(*remain)[i].b[1][0] = '\0';
	}
	return (0);
}

int						get_next_line(int const fd, char **line)
{
	static t_gnl		*remain;
	char				*endl;
	int					exitval;
	size_t				len;

	if (init_gnl(fd, line, &remain))
		return (-1);
	if ((endl = ft_strchr(GNL_REM1, '\n')) == NULL)
	{
		len = ft_strlen(GNL_REM1);
		if ((exitval = rec_gnl(fd, line, remain, len)) < 0)
			return (-1);
		ft_memcpy(*line, GNL_REM1, len);
		remain[fd].turn = !remain[fd].turn;
		return (exitval);
	}
	*line = ft_strndup(GNL_REM1, endl - GNL_REM1);
	(*line)[endl - GNL_REM1] = '\0';
	remain[fd].turn = !remain[fd].turn;
	ft_strcpy(GNL_REM1, endl + 1);
	return (1);
}
