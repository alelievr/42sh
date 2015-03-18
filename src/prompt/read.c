#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <ncurses.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>

typedef long long
		unsigned int	t_lluint;

#define BUFF_SIZE		0xf0000

void					aff_buffer(char buffer[BUFF_SIZE], size_t index)
{
	static char			buff[4096];
//	char				*tbuff;

//	tbuff = buff;
	write(1, "\033[0G\033[0J", 8);
//	tgetstr("ch", &tbuff);
//	tgetstr("kE", &tbuff);
//	write(1, buff, strlen(buff));
	write(1, buffer, strlen(buffer));
	sprintf(buff, "\033[%luG", index + 1);
	write(1, buff, strlen(buff));
}

void					add_char(char buffer[BUFF_SIZE], char c, size_t *index)
{
	size_t				tmp;

	tmp = strlen(buffer);
	buffer[tmp + 1] = '\0';
	while (tmp != *index)
	{
		buffer[tmp] = buffer[tmp - 1];
		--tmp;
	}
	buffer[tmp] = c;
	++*index;
}

void					rem_char(char buffer[BUFF_SIZE], size_t index)
{
	size_t				tmp;

	tmp = index;
	while (buffer[tmp])
	{
		buffer[tmp] = buffer[tmp + 1];
		++tmp;
	}
}

void					ft_read(void)
{
	static char			buffer[BUFF_SIZE] = {'\0'};
	size_t				index;
	static t_lluint		key = 0;

	index = 0;
	while (read(0, &key, 8))
	{
//		printf("%llu\n", key);
		if (isprint(0xff & key) && (key != 9u))
			add_char(buffer, 0xff & key, &index);
		else if ((key == 127ull) && (index))
			rem_char(buffer, --index);
		else if ((key == 2117294875ull) && buffer[index])
			rem_char(buffer, index);
		else if ((key == 4414235ull) && buffer[index])
			++index;
		else if ((key == 4479771ull) && index)
			--index;
		else if (key == 10ull)
			break ;
		else if (key == 4ull)
			return ;
		key = 0;
		aff_buffer(buffer, index);
	}
}

int						main(void)
{
	char				*name_term;
	struct termios		term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	ft_read();
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}
