# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdaudre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/15 15:13:38 by fdaudre-          #+#    #+#              #
#    Updated: 2015/03/16 17:46:22 by fdaudre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Auteur: fdaudre-

#################
##  VARIABLES  ##
#################

#	Sources
SRCDIR		=	.
SRC			=	ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isblank.c		\
				ft_ispunct.c		\
				ft_isspace.c		\
				ft_isupper.c		\
				ft_islower.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_lstback.c		\
				ft_lsttostr.c		\
				ft_strndup.c		\
				ft_simpledel.c		\
				ft_power.c			\
				ft_sqrt.c			\
				ft_lstsort.c		\
				ft_lstprint.c		\
				ft_simpleprint.c	\
				ft_gnl.c			\
				ft_nbrlen.c			\
				ft_unbrlen.c		\
				ft_wstrlen.c		\
				ft_put_pixel.c		\
				ft_put_line.c		\
				ft_put_line2.c		\
				ft_mlxkey_get.c		\
				ft_mlxkey_set.c		\
				ft_mat_new.c		\
				ft_mat_add.c		\
				ft_mat_mul.c		\
				ft_mat_sub.c		\
				ft_mat_disp.c		\
				ft_ndigitsbase.c	\
				ft_nmatch.c			\
				ft_memmem.c			\
				ft_strrev.c			\
				ft_dbg.c			\
				ft_syserrlist.c		\
				ft_errnullptr.c					\
				ft_printf/ft_printf.c			\
				ft_printf/ft_vprintf.c			\
				ft_printf/init.c				\
				ft_printf/convs/conv_char.c		\
				ft_printf/convs/conv_color.c	\
				ft_printf/convs/conv_int.c		\
				ft_printf/convs/conv_str.c		\
				ft_printf/convs/conv_udec.c		\
				ft_printf/convs/conv_uhex.c		\
				ft_printf/convs/conv_uoct.c		\
				ft_printf/flags/flag_base.c		\
				ft_printf/flags/flag_color.c	\
				ft_printf/flags/flag_j.c		\
				ft_printf/flags/flag_long.c		\
				ft_printf/flags/flag_minus.c	\
				ft_printf/flags/flag_number.c	\
				ft_printf/flags/flag_plus.c		\
				ft_printf/flags/flag_prec.c		\
				ft_printf/flags/flag_prefix.c	\
				ft_printf/flags/flag_short.c	\
				ft_printf/flags/flag_space.c	\
				ft_printf/flags/flag_star.c		\
				ft_printf/flags/flag_z.c		\
				ft_printf/flags/flag_zero.c		\
				ft_printf/forms/format_int.c	\
				ft_printf/forms/format_str.c	\
				ft_printf/forms/format_uint.c	\
				ft_printf/forms/format_wstr.c	\
				ft_printf/forms/write_uint.c	\

#	Objects
OBJDIR		=	obj

#	Includes
INCDIR		=	. ft_printf

#	Libraries
LIBDIR		=	
LIB			=	

#	Output
NAME		=	libft.a

#	Compiler
CFLAGS		=	-O3 -Werror -Wall -Wextra
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
	$(eval VPATH_TMP += $(SRCDIR)/$(dir $(S)) \
))
VPATH		=	$(VPATH_TMP:./=)

disp_indent	=	for I in `seq 1 $(MAKELEVEL)`; do \
					test "$(MAKELEVEL)" '!=' '0' && printf "\t"; \
				done

exec_color	=	$(call disp_indent); \
			echo $(1)$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)"\033[31m"; \
			$(2) $(3) $(4) $(5) $(6) $(7) $(8) $(9) $(10)

disp_title	=	$(call disp_indent); \
				echo "\033[1;$(2);7m[  $(1) \#$(MAKELEVEL)  ]\033[0m"


#################
##  TARGETS    ##
#################

#	First target
all: $(NAME)

#	Linking
$(NAME): $(OBJ)
	@$(call disp_title,Linking,32);
	@$(call exec_color,"\033[0;1;32m➤ \033[0;38;5;85m",\
		ar, rc, $(NAME), $(OBJ)) # <- Linking command
	@$(call exec_color,"\033[0;1;32m➤ \033[0;38;5;85m",\
		ranlib, $(NAME))

#	Objects compilation
$(OBJDIR)/%.o: %.c
	@if [ $(ALREADY_OBJ)x != xx ]; then \
		$(call disp_title,Building,36); \
	fi
	@mkdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@$(call exec_color,"\033[0;1;36m➤ \033[0;38;5;159m",\
		$(CC), $(CFLAGS), $(INCFLAG), -o, $@, -c, $<) # <- Building command
	@$(eval ALREADY_OBJ=x)

#	Removing objects
clean:
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,33); \
	fi
	@$(call exec_color,"\033[0;1;33m➤ \033[0;38;5;229m",\
		rm -f, $(OBJ)) # <- Cleaning objs
	@rmdir $(OBJDIR) 2> /dev/null || echo "" > /dev/null
	@$(eval ALREADY_RM=x)

#	Removing objects and exe
fclean: clean
	@if [ $(ALREADY_RM)x != xx ]; then \
		$(call disp_title,Cleaning,33); \
	fi
	@$(call exec_color,"\033[0;1;33m➤ \033[0;38;5;229m",\
		rm -f, $(NAME)) # <- Cleaning binary
	@$(eval ALREADY_RM=x)

#	All removing then compiling
re: fclean all

#	Checking norme
norme:
	@$(call disp_title,Norme,37)
	@norminette $(NORME) | sed "s/Norme/[0;1;37m➤ [0;38;5;254mNorme/g;s/Warning/[0;31mWarning/g;s/Error/[0;31mError/g"

run: $(NAME)
	@echo "\033[1;35;7m[  Running #$(MAKELEVEL)  ]\033[0m"
	@echo "\033[0;1;35m➤ \033[0;38;5;147m./$(NAME) ${ARGS}\033[0m"
	@./$(NAME) ${ARGS}

codesize:
	@cat $(NORME) |grep -v '/\*' |wc -l

.PHONY: all clean fclean re norme codesize
