#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	src
MAIN_SRC	=	main/main.c								\
				main/ft_signals.c						\
				main/ft_prompt.c						\
				main/process_pid_api.c					\
				main/rw_history.c						\
				main/bin_hashtable.c					\
				main/hashtable_utils.c					\
				main/killall_process.c					\

UTIL_SRC	=	utils/path_utils.c						\
				utils/is_utils.c						\
				utils/log.c								\

BUILTIN_SRC	=	builtins/build_env.c					\
				builtins/ft_env.c						\
				builtins/ft_builtins.c					\
				builtins/ft_exit.c						\
				builtins/ft_unsetenv.c					\
				builtins/ft_unset.c						\
				builtins/ft_setenv.c					\
				builtins/ft_set.c						\
				builtins/ft_echo.c						\
				builtins/ft_getenv.c					\
				builtins/ft_get.c						\
				builtins/ft_cd.c						\
				builtins/ft_bonus.c						\
				builtins/unset_env.c					\
				builtins/unset_var.c					\
				builtins/get_env.c						\
				builtins/get_var.c						\
				builtins/set_env.c						\
				builtins/set_var.c						\
				builtins/job_control.c					\
				builtins/ft_history.c					\
				builtins/ft_alias.c						\
				builtins/ft_where.c						\

PROMPT_SRC	=	prompt/get_command.c					\
				prompt/pr_addch.c						\
				prompt/pr_del.c							\
				prompt/pr_move.c						\
				prompt/pr_tab.c							\
				prompt/pr_history.c						\
				prompt/pr_history_api.c					\
				prompt/pr_utils.c						\
				prompt/raw_terminal_mode.c				\
				prompt/default_terminal_mode.c			\
				prompt/pr_unterminated_seq.c			\
				prompt/pr_display.c						\
				prompt/pr_multiline.c					\
				prompt/pr_vim_export.c					\

PARSER_SRC	=	preparser/preparser.c					\
				preparser/split_quote.c					\
				preparser/split_quote_table.c			\
				preparser/replace_vars.c				\
				preparser/replace_alias.c				\
				preparser/globing_expand.c				\
				preparser/globing_expand_braces.c		\
				preparser/globing_expand_wildcard.c		\
				preparser/globing.c						\
				preparser/globing_file.c				\

LEXER_SRC	=	lexer/lex.c								\
				lexer/print_cmd_line.c					\
				lexer/lex_new.c							\
				lexer/lex_op.c							\
				lexer/lex_redir.c						\
				lexer/lex_current.c						\
				lexer/lex_add.c							\
				lexer/lex_double_redir.c				\
				lexer/lex_redir_template.c				\
				lexer/lex_utils.c						\

EXEC_SRC	=	executer/executer.c						\
				executer/execute_command_line.c			\
				executer/execute_command.c				\
				executer/execute_operator.c				\
				executer/execute_binary.c				\
				executer/execute_pipe.c					\
				executer/execute_pid.c					\
				executer/execute_utils.c				\
				executer/execute_pipe_buff.c			\

SRC			=	$(MAIN_SRC)		\
				$(UTIL_SRC)		\
				$(BUILTIN_SRC)	\
				$(PROMPT_SRC)	\
				$(PARSER_SRC)	\
				$(EXEC_SRC)		\
				$(LEXER_SRC)	\


#	Objects
OBJDIR		=	obj

#	Includes
INCDIR		=	. libft

#	Libraries
LIBDIR		=	libft
LIB			=	-lft -lncurses

#	Output
NAME		=	42sh

#	Compiler
CFLAGS		=	-g -Werror -Wall -Wextra -O2 -fsanitize=address
CC			=	clang

#################
##  AUTO       ##
#################

SHELL		=	/bin/zsh
OBJ			=	$(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))
LIBFLAG		=	$(addprefix -L,$(LIBDIR))
INCFLAG		=	$(addprefix -I,$(INCDIR))
NORME		=	$(addsuffix /*.h,$(INCDIR)) $(addprefix $(SRCDIR)/,$(SRC))

$(foreach S,$(SRC), \
	$(eval VPATH += $(SRCDIR)/$(dir $(S)) \
	) \
	)

#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Linking
$(NAME): $(OBJ)
	@make -C libft
	@echo "\033[38;5;149m⇒ Linking:"
	@echo "\033[38;5;148m⇒ \033[38;5;149m"$(CC) $(CFLAGS) $(LIBFLAG) -o $(NAME) $(LIB) $(OBJ)"\033[31m"
	@$(CC) $(CFLAGS) $(LIBFLAG) -o $(NAME) $(LIB) $(OBJ)

#	Objects compilation
$(OBJDIR)/%.o: %.c
	@if [ $(ALREADY_OBJ)x != xx ]; then \
		echo "\033[38;5;135mBuilding:"; \
		fi
	@mkdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@echo "\033[38;5;123m⇒ \033[38;5;159m"$(CC) $(CFLAGS) $(INCFLAG) -o $@ -c $<"\033[31m"
	@$(CC) $(CFLAGS) $(INCFLAG) -o $@ -c $<
	$(eval ALREADY_OBJ=x)

#	Removing objects
clean:
	@if [ $(ALREADY_RM)x != xx ]; then \
		echo "\033[38;5;53mCleaning:"; \
		fi
	@printf "\033[38;5;52m⇒ \033[38;5;53m"
	rm -fv $(OBJ) >/dev/null
	@rmdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@printf "\033[31m"
	$(eval ALREADY_RM=x)

#	Removing objects and exe
fclean: clean
	@if [ $(ALREADY_RM)x != xx ]; then \
		echo "\033[38;5;53mCleaning:"; \
		fi
	@printf "\033[38;5;52m⇒ \033[38;5;53m"
	rm -fv $(NAME) >/dev/null
	@printf "\033[31m"
	$(eval ALREADY_RM=x)

#	All removing then compiling
re: fclean all

#	Checking norme
norme:
	@echo "\033[38;5;47mNorme:"
	@norminette $(NORME)\
		| sed "s/Norme/[0;1;37m➤ [38;5;47mNorme/g;s/Warning/[0;31mWarning/g;s/Error/[0;31mError/g"

run: $(NAME)
	@printf "\033[0m"
	./$(NAME)

codesize:
	@cat $(foreach S,$(SRC), $(SRCDIR)/$(S)) |grep -v '/\*' |wc -l

.PHONY: all clean fclean re norme codesize
