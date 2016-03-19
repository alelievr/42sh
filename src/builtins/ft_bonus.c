#include "ft_42sh.h"

int			ft_bonus(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("bonuses list:\n");
	ft_printf("local variables (set and unset builtins)\n");
	ft_printf("line edition (shift-right, shift-left, ctrl-a and ctrl-e)\n");
	ft_printf("dynamic completion with tab, if 0 matches -> beep\n");
	ft_printf("reconstruction of the environement if vars are missing + SHLVL\n");
	ft_printf("job control jobs, fg, bg, ctrl-z and &\n");
	ft_printf("aliases\n");
	ft_printf("where command builtin\n");
	ft_printf("Ctrl-P to export your command in a vim file to edit it\n");
	ft_printf("hashtable for binarys\n");
	ft_printf("inibitors (\', \" and \\\")\n");
	ft_printf("local and env variables in command line $... and ~\n");
	ft_printf("TODO: unterminated quote, dbqutoe or () on multiline prompt\n");
	ft_printf("TODO: <<\n");
	ft_printf("TODO: globing: *, ?, [], {} (and ** ?)\n");
	ft_printf("TODO: ` and $()\n");
	ft_printf("TODO: history, !, !!, up and down key\n");
	ft_printf("TODO: ctrl-R for history searches\n");
	ft_printf("TODO: advanced autocompletion: expand `command`, $... vars and globing\n");
	ft_printf("TODO: super advanced autocompletion: display a selectable list of matches, when ./<TAB> only binay are listed, if there is one result to autocompletion and it's a directory, a / is append to continue the autocomplete, strstr nonsensitive complete Strcpy<TAB> -> ft_strcpy.c and finally, a command relative completion cd -> only dirs, nm -> only binarys ...\n");
	return (0);
}
