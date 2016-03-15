/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:51:11 by fdaudre-          #+#    #+#             */
/*   Updated: 2016/03/15 23:42:04 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# include "ft_printf/ft_printf.h"

extern char const			*const g_serr[];

# define LIBFT_DEBUG		0

# define FT_DBG				ft_dbg(__FILE__, __LINE__)

# define MAX(X, Y)			(X > Y ? X : Y)
# define MIN(X, Y)			(X < Y ? X : Y)
# define SIGN(X)			(X < 0 ? -1 : 1)
# define ABS(X)				(X < 0 ? -X : X)



# define BIT_VAL(nbr, r)	(nbr & (1L << (r - 1)))
# define BIT_ON(nbr, r)		(nbr |= (1L << (r - 1)))
# define BIT_OFF(nbr, r)	(nbr &= ~(1L << (r - 1)))
# define BIT_CMP(nbr1, nbr2, r)	(BIT_VAL(nbr1, r) - BIT_VAL(nbr2, r))

# define FIRST_OCC(str, c)	(int)(ft_strchr(str, c) - str)
# define LAST_OCC(str, c)	(int)(ft_strrchr(str, c) - str)

/*
** for (i = 0; i < 10; i++)	:	if (FOR(i = 0, i < 10, i++))
*/

# define T(expr, yes, no)	(expr ? yes : no)
# define GOTO(lbl)			goto lbl
# define FOR(a, b, c)		0){;} for ((a); (b); (c)
# define SWITCH(x)			0){;} switch (x
# define CASE(x);			case x:

# define FT_DCOL			25
# define FT_WCOL			202
# define FT_ECOL			196

# define FT_LSTSORT			int (*)(const void *, const void *)

# define IFRET__(x, y)		if (x) return (y);

# define LOMAGIC			0x1010101010101010
# define HIMAGIC			0x8080808080808080
# define LONGCHR_NULL(x)	(((x - LOMAGIC) & HIMAGIC) != 0)

typedef enum			e_bool
{
	FALSE = 0,
	TRUE
}						t_bool;

typedef unsigned long long int	t_op;

/*
** Memory
*/
void					ft_bzero(void *s, size_t n);
void					*ft_memset(void *b, int c, size_t len);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
							size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memmem(const void *big, size_t big_len,
							const void *little, size_t little_len);

void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);

/*
** Strings
*/
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *s1, const char *s2);
char					*ft_strnstr(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_strrev(char *str);

char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(const char *s, char (*f)(char));
char					*ft_strmapi(const char *s, char (*f)(unsigned int,
							char));

int						ft_strequ(const char *s1, const char *s2);
int						ft_strnequ(const char *s1, const char *s2, size_t n);
char					*ft_strsub(const char *s, unsigned int start,
							size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *s);
char					**ft_strsplit(const char *s, char const *c);

int						ft_toupper(int c);
int						ft_tolower(int c);

int						ft_atoi(const char *str);

size_t					ft_wstrlen(const wchar_t *str);

int						nmatch(char *s1, char *s2);

/*
** Chars
*/
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_isblank(int c);
int						ft_ispunct(int c);
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);

/*
** Display
*/
int						get_stdout(void);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putstdout(char const *s);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);

/*
** Numbers
*/
int						ft_power(int nb, int power);
int						ft_sqrt(int nb);

int						ft_ndigitsbase(uint64_t nbr, size_t base);
size_t					ft_nbrlen(int64_t nbr, const size_t base);
size_t					ft_unbrlen(uint64_t nbr, const size_t base);

int64_t					ft_deconvert(char *n, int b);
int64_t					ft_ndeconvert(char *n, int b, int len);

/*
** Linked list
*/
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **link,
							void (*del)(void *, size_t));
void					ft_lstdel(t_list **link, void (*del)(void *, size_t));
void					ft_lstadd(t_list **link, t_list *newl);
void					ft_lstiter(t_list *lst, void (*f)(t_list *link));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *link));
void					ft_lstback(t_list *link, t_list *newl);
char					*ft_lsttostr(t_list *lst);
void					ft_simpledel(void *content, size_t content_size);
void					ft_lstsort(t_list *lst,
							int(*f)(const void *, const void *));
void					ft_lstprint(const t_list *lst,
							void (*f)(const void *, size_t));
void					ft_simpleprint(const void *content, size_t size);

/*
** Debug
*/
void					ft_dbg(char *file, int line);
void					ft_errnullptr(char const *str);
void					m_error(void);

/*
** Matrix calculation
*/
# define FT_MAT_DIM		4
# undef tab

typedef struct			s_matrix
{
	unsigned char		m;
	unsigned char		n;
	double				tab[FT_MAT_DIM][FT_MAT_DIM];
}						t_matrix;

t_matrix				*ft_mat_new(unsigned char m, unsigned char n,
							double tab[FT_MAT_DIM][FT_MAT_DIM]);
t_matrix				*ft_mat_add(t_matrix *m1, t_matrix *m2, t_matrix *res);
t_matrix				*ft_mat_sub(t_matrix *m1, t_matrix *m2, t_matrix *res);
t_matrix				*ft_mat_mul(t_matrix *m1, t_matrix *m2, t_matrix *res);
void					ft_mat_disp(t_matrix *m);

/*
** Geometrie
*/
typedef struct			s_2dpt
{
	int					x;
	int					y;
}						t_2dpt;

typedef struct			s_3dpt
{
	int					x;
	int					y;
	int					z;
}						t_3dpt;

typedef struct			s_mlximg
{
	void				*img_ptr;
	char				*img;
	int					bpp;
	int					lsize;
	int					nlines;
	int					endian;
	int					min;
	int					max;
}						t_mlximg;

void					ft_put_pixel(t_mlximg *datas, t_2dpt *p, int color);
void					ft_put_line(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant1(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant2(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant3(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);
void					ft_put_line_octant4(t_mlximg *datas,
							int (*f)(const t_mlximg *datas, const t_matrix *,
							const t_matrix *, t_2dpt *),
							const t_matrix *p1, const t_matrix *p2);

/*
** mlx events
*/
void					ft_mlxkey_set(int64_t tabkey[512],
							int index, t_bool value);
int						ft_mlxkey_get(int64_t tabkey[512], int index);

/*
** get_next_line
*/
# define FT_GNL_MAXFD	256
# define FT_GNL_BUFSIZE	128

typedef struct			s_gnl
{
	char				b[2][FT_GNL_BUFSIZE];
	int					turn;
}						t_gnl;

int						ft_gnl(const int fd, char **line);
int						get_next_line(int const fd, char **line);

#endif
