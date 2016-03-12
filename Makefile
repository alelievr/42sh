#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	src
SRC			=	main.c									\
				build_env.c								\
				ft_env.c								\
				ft_exebin.c								\
				ft_builtins.c							\
				ft_exit.c								\
				ft_unsetenv.c							\
				ft_unset.c								\
				ft_setenv.c								\
				ft_set.c								\
				ft_echo.c								\
				ft_getenv.c								\
				ft_get.c								\
				ft_cd.c									\
				ft_bonus.c								\
				unset_env.c								\
				unset_var.c								\
				get_env.c								\
				get_var.c								\
				set_env.c								\
				set_var.c								\
				ft_signals.c							\
				ft_exec.c								\
				execute_command.c						\
				default_terminal_mode.c					\
				raw_terminal_mode.c						\
				utils.c									\
				prompt_test.c							\
				prompt/get_command.c					\
				prompt/pr_addch.c						\
				prompt/pr_del.c							\
				prompt/pr_move.c						\
				prompt/pr_tab.c							\
				prompt/pr_history.c						\
				prompt/pr_history_api.c					\
				parser/parse.c							\
				operation/ft_pipe.c						\
				operation/ft_right_redir.c				\
				operation/ft_redir_stdin_stdout.c		\
				operation/ft_double_right_redir.c		\
				operation/ft_error_double_right_redir.c	\
				operation/ft_error_right_redir.c		\
				operation/ft_double_left_redir.c		\
				operation/ft_left_redir.c				\


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
CFLAGS		=	-g -Werror -Wall -Wextra -O2
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
