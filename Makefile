#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	src
MAIN_SRC	=	main.c									\
				ft_signals.c							\
				execute_command.c						\
				ft_prompt.c								\
				process_pid_api.c						\
				rw_history.c							\

UTIL_SRC	=	utils/path_utils.c						\
				utils/is_utils.c						\

BUILTIN_SRC	=	builtins/build_env.c					\
				builtins/ft_env.c						\
				builtins/ft_exebin.c					\
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

PARSER_SRC	=	parser/parse.c							\

OPER_SRC	=	operation/ft_pipe.c						\
				operation/ft_right_redir.c				\
				operation/ft_redir_stdin_stdout.c		\
				operation/ft_double_right_redir.c		\
				operation/ft_error_double_right_redir.c	\
				operation/ft_error_right_redir.c		\
				operation/ft_double_left_redir.c		\
				operation/ft_left_redir.c				\

SRC			=	$(MAIN_SRC)		\
				$(UTIL_SRC)		\
				$(BUILTIN_SRC)	\
				$(PROMPT_SRC)	\
				$(PARSER_SRC)	\
				$(OPER_SRC)		\


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
CFLAGS		=	-g -Werror -Wall -Wextra -O0 -fsanitize=address
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
	rm -fv $(OBJ)
	@rmdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@printf "\033[31m"
	$(eval ALREADY_RM=x)

#	Removing objects and exe
fclean: clean
	@if [ $(ALREADY_RM)x != xx ]; then \
		echo "\033[38;5;53mCleaning:"; \
		fi
	@printf "\033[38;5;52m⇒ \033[38;5;53m"
	rm -fv $(NAME)
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
	@cat $(SRC) |grep -v '/\*' |wc -l

.PHONY: all clean fclean re norme codesize
