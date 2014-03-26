#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 17:00:44 by aardjoun          #+#    #+#              #
#    Updated: 2014/03/26 05:47:57 by rkharif          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME	=	42sh

SRCS	=	srcs/main/main.c\
			srcs/main/ft_mishell.c\
			srcs/main/built.c\
			srcs/main/options.c\
			srcs/environ/ft_env.c\
			srcs/environ/function_env.c\
			srcs/errors/error.c\
			srcs/errors/error_2.c\
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
			srcs/read/buttons_functions.c\
			srcs/read/history.c\
			srcs/read/read.c\
			srcs/read/read_function.c\
			srcs/read/syntax_color.c\
			srcs/read/termcap.c\
			srcs/read/autocomplete.c\
			srcs/read/autocomplete_function.c \
			srcs/read/t_options.c\
			srcs/read/show_autocomplete.c\
			srcs/read/show_option.c\
			srcs/read/parser_color.c\
			srcs/read/parser_color_function.c\
			srcs/read/parser_color_command.c\
			srcs/read/parsing_man.c\
			srcs/read/parsing_man_function.c\
			srcs/read/spe_autocomp.c\
			srcs/read/autocomplete_too_long.c\
			srcs/builtin/exit.c\
			srcs/builtin/echo.c\
			srcs/builtin/cd.c\
			srcs/builtin/variable.c\
			srcs/builtin/variable_2.c\
			srcs/builtin/conf.c\
			srcs/builtin/no_conf.c\
			srcs/builtin/alias.c\
			srcs/builtin/jobs.c\
			srcs/prompt/prompt_interpreter.c\
			srcs/prompt/prompt.c\
			srcs/prompt/prompt_func.c\
			srcs/parser/parser.c\
			srcs/parser/lex.c\
			srcs/parser/check_line.c\
			srcs/parser/check_func.c\
			srcs/parser/check_redir.c\
			srcs/pipe/check_redirection.c\
			srcs/pipe/pipe.c\
			srcs/pipe/pipe_function.c\
			srcs/pipe/redirection.c\
			srcs/signal/signal.c\
			srcs/signal/show_stop.c\
			srcs/signal/function_list.c\
			srcs/operators/operator.c \
			srcs/autocomplete/autocomp.c \
			srcs/autocomplete/spe_autocomp.c


HDRS	=	includes/msh.h

CFLAGS = -g -Wall -Wextra -Werror

CC		=	gcc

LIBS	=	-L/usr/lib/ -ltermcap

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	 $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)
	@echo "done"

clean	:
	@rm -rf $(OBJS)
	@echo "clean done"

fclean	:	clean
	@rm -rf $(NAME)
	@echo "fclean done"

install42: all
	cp msh ~/.brew/bin/

install: all
	cp msh /usr/bin/

re		:	fclean all

.PHONY	:	all re fclean clean
