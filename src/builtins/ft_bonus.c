#include "ft_42sh.h"

int			ft_bonus(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_printf("bonuses list:\n");
	ft_printf("local variables (set and unset builtins)\n");
	ft_printf("line edition (shift-right, shift-left, ctrl-a, ctrl-e, ctrl-u, ctrl-k, (TODO: ctrl-l))\n");
	ft_printf("dynamic completion with tab, if 0 matches -> beep\n");
	ft_printf("reconstruction of the environement if vars are missing + SHLVL\n");
	ft_printf("job control jobs, fg, bg, ctrl-z and &\n");
	ft_printf("aliases\n");
	ft_printf("where command builtin\n");
	ft_printf("Ctrl-P to export your command in a vim file to edit it\n");
	ft_printf("hashtable for binarys\n");
	ft_printf("inibitors (\', \" and \\\")\n");
	ft_printf("local and env variables in command line $... and ~\n");
	ft_printf("history, (TODO: (!, !!) up and down key\n");
	ft_printf("globing: *, ?, [], {} (TODO ** ?)\n");
	ft_printf("TODO: source file (~/.42shrc)\n");
	ft_printf("TODO: builtin: disown\n");
	ft_printf("TODO: builtin: fc\n");
	ft_printf("TODO: builtin: wait\n");
	ft_printf("TODO: builtin: unalias\n");
	ft_printf("TODO: unterminated quote, dbqutoe or () on multiline prompt\n");
	ft_printf("TODO: advanced builtins: $?, $$, $!, $_, ($*, $@, $#, $-); cd -1, -2, ...; !-1, !-2 ...\n");
	ft_printf("TODO: advanced ${} operations: ${#var}, ${var/s/s} ...\n");
	ft_printf("TODO: <<\n");
	ft_printf("TODO: ` and $()\n");
	ft_printf("TODO: ctrl-R for history searches\n");
	ft_printf("TODO: advanced autocompletion: expand `command`, $... vars and globing\n");
	ft_printf("TODO: super advanced autocompletion: display a selectable list of matches, when ./<TAB> only binay are listed, if there is one result to autocompletion and it's a directory, a / is append to continue the autocomplete, strstr nonsensitive complete Strcpy<TAB> -> ft_strcpy.c and finally, a command relative completion cd -> only dirs, nm -> only binarys ...\n");
	return (0);
}
