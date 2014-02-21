#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 17:00:44 by aardjoun          #+#    #+#              #
#    Updated: 2014/02/21 19:03:14 by lsolofri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	MiShell

SRCS	=	srcs/main/main.c\
			srcs/main/ft_mishell.c\
			srcs/main/built.c\
			srcs/environ/find_value_envir.c\
			srcs/environ/ft_env.c\
			srcs/environ/get_man_path.c\
			srcs/errors/error.c\
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
			srcs/functions/ft_tabncmp.c\
			srcs/functions/get_next_line.c\
			srcs/functions/ft_atoi.c\
			srcs/read/actions.c\
			srcs/read/buttons.c\
			srcs/read/history.c\
			srcs/read/read.c\
			srcs/read/syntax_color.c\
			srcs/read/termcap.c\
			srcs/read/autocomplete.c\
			srcs/read/t_options.c\
			srcs/read/show_autocomplete.c\
			srcs/read/syntax_color_rest.c\
			srcs/read/show_option.c\
			srcs/read/parsing_man.c\
			srcs/builtin/exit.c\
			srcs/builtin/echo.c\
			srcs/prompt/prompt_interpreter.c\
			srcs/prompt/prompt.c

HDRS	=	includes/msh.h

CFLAGS = -g -Wall -Wextra -Werror

CC		=	gcc

LIBS	=	-L/usr/lib/ -ltermcap

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all re fclean clean
