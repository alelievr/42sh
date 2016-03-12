#include "ft_42sh.h"

int			ft_bonus(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("bonuses list:\n");
	ft_printf("local variables (set and unset builtins)\n");
	ft_printf("line edition (shift-right, shift-left, ctrl-a and ctrl-e)\n");
	ft_printf("dynamic completion with tab\n");
	ft_printf("reconstruction of the environement if vars are missing + SHLVL");
	ft_printf("TODO: inibitors (\', \" and \\\")\n");
	ft_printf("TODO: <<\n");
	ft_printf("TODO: globing: *, ?, [], {} (and ** ?)\n");
	ft_printf("TODO: `\n");
	ft_printf("TODO: history, !, !! and up key\n");
	ft_printf("TODO: job control fg, bg, ctrl-z and &\n");
	ft_printf("TODO: aliases\n");
	ft_printf("TODO: local and env variables in command line $... and ~\n");
	ft_printf("TODO: advanced autocompletion: exand `command`, $... vars and globing\n");
	ft_printf("TODO: super advanced autocompletion: display a selectable list of matches, when ./<TAB> only binay are listed, if there is one result to autocompletion and it's a directory, a / is append to continue the autocomplete\n");
	return (0);
}
