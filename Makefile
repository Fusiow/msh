#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 17:00:44 by aardjoun          #+#    #+#              #
#    Updated: 2014/03/23 18:30:37 by lsolofri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	MiShell

SRCS	=	srcs/main/main.c\
			srcs/main/ft_mishell.c\
			srcs/main/built.c\
			srcs/main/options.c\
			srcs/environ/ft_env.c\
			srcs/environ/get_man_path.c\
			srcs/errors/error.c\
			srcs/errors/cd_error.c\
			srcs/functions/ft_isdigit.c\
			srcs/functions/ft_free_tab.c\
			srcs/functions/ft_get_path.c\
			srcs/functions/ft_isprint.c\
			srcs/functions/ft_new_tab.c\
			srcs/functions/ft_putchar.c\
			srcs/functions/ft_putendl.c\
			srcs/functions/ft_putnbr.c\
			srcs/functions/ft_putstr.c\
			srcs/functions/ft_strcmp.c\
			srcs/functions/ft_strdup.c\
			srcs/functions/ft_strjoin.c\
			srcs/functions/ft_strlen.c\
			srcs/functions/ft_strncmp.c\
			srcs/functions/ft_strsplit.c\
			srcs/functions/ft_strsub.c\
			srcs/functions/ft_tablen.c\
			srcs/functions/ft_isalpha.c\
			srcs/functions/ft_itoa.c\
			srcs/functions/ft_tabncmp.c\
			srcs/functions/get_next_line.c\
			srcs/functions/ft_atoi.c\
			srcs/functions/ft_cmd_result.c\
			srcs/functions/welcome.c\
			srcs/functions/ft_insert_tab.c\
			srcs/functions/ft_memalloc.c\
			srcs/functions/ft_gc.c\
			srcs/functions/ft_gchelper.c\
			srcs/functions/ft_bzero.c\
			srcs/functions/ft_free.c\
			srcs/functions/ft_strnew.c\
			srcs/functions/ft_memcpy.c\
			srcs/functions/ft_isdirectory.c\
			srcs/read/actions.c\
			srcs/read/buttons.c\
			srcs/read/history.c\
			srcs/read/read.c\
			srcs/read/syntax_color.c\
			srcs/read/termcap.c\
			srcs/read/autocomplete.c\
			srcs/read/t_options.c\
			srcs/read/show_autocomplete.c\
			srcs/read/show_option.c\
			srcs/read/parser_color.c\
			srcs/read/parsing_man.c\
			srcs/read/spe_autocomp.c\
			srcs/read/autocomplete_too_long.c\
			srcs/builtin/exit.c\
			srcs/builtin/echo.c\
			srcs/builtin/cd.c\
			srcs/builtin/variable.c\
			srcs/builtin/conf.c\
			srcs/builtin/no_conf.c\
			srcs/builtin/alias.c\
			srcs/builtin/jobs.c\
			srcs/prompt/prompt_interpreter.c\
			srcs/prompt/prompt.c\
			srcs/parser/parser.c\
			srcs/parser/lex.c\
			srcs/parser/check_line.c\
			srcs/pipe/check_redirection.c\
			srcs/pipe/pipe.c\
			srcs/pipe/pipe_function.c\
			srcs/pipe/redirection.c\
			srcs/signal/signal.c\
			srcs/signal/show_stop.c\
			srcs/signal/function_list.c\
			srcs/operators/operator.c \
			srcs/autocomplete/autocomp.c


HDRS	=	includes/msh.h

CFLAGS = -g -Wall -Wextra -Werror

CC		=	gcc

LIBS	=	-L/usr/lib/ -ltermcap

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

msh		:
	@echo "MMMMMMMM               MMMMMMMM   SSSSSSSSSSSSSSS HHHHHHHHH     HHHHHHHHH"
	@echo "M:::::::M             M:::::::M SS:::::::::::::::SH:::::::H     H:::::::H"
	@echo "M::::::::M           M::::::::MS:::::SSSSSS::::::SH:::::::H     H:::::::H"
	@echo "M:::::::::M         M:::::::::MS:::::S     SSSSSSSHH::::::H     H::::::HH"
	@echo "M::::::::::M       M::::::::::MS:::::S              H:::::H     H:::::H"
	@echo "M:::::::::::M     M:::::::::::MS:::::S              H:::::H     H:::::H"
	@echo "M:::::::M::::M   M::::M:::::::M S::::SSSS           H::::::HHHHH::::::H"
	@echo "M::::::M M::::M M::::M M::::::M  SS::::::SSSSS      H:::::::::::::::::H"
	@echo "M::::::M  M::::M::::M  M::::::M   SSS::::::::SS     H:::::::::::::::::H"
	@echo "M::::::M   M:::::::M   M::::::M      SSSSSS::::S    H::::::HHHHH::::::H"
	@echo "M::::::M    M:::::M    M::::::M            S:::::S  H:::::H     H:::::H"
	@echo "M::::::M     MMMMM     M::::::M            S:::::S  H:::::H     H:::::H"
	@echo "M::::::M               M::::::MSSSSSSS     S:::::SHH::::::H     H::::::HH"
	@echo "M::::::M               M::::::MS::::::SSSSSS:::::SH:::::::H     H:::::::H"
	@echo "M::::::M               M::::::MS:::::::::::::::SS H:::::::H     H:::::::H"
	@echo "MMMMMMMM               MMMMMMMM SSSSSSSSSSSSSSS   HHHHHHHHH     HHHHHHHHH"

$(NAME)	:	 $(OBJS) msh
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "done"

clean	:
	@rm -rf $(OBJS)
	@echo "clean done"

fclean	:	clean
	@rm -rf $(NAME)
	@echo "fclean done"

re		:	fclean all

.PHONY	:	all re fclean clean
