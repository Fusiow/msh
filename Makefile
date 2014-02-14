#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aardjoun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/14 17:00:44 by aardjoun          #+#    #+#              #
#    Updated: 2014/02/14 17:31:32 by aardjoun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	MiShell

SRCS	=	srcs/main/main.c\
			srcs/main/ft_mishell.c\
			srcs/environ/find_value_envir.c\
			srcs/environ/ft_env.c\
			srcs/environ/get_man_path.c\
			srcs/errors/error.c\
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
			srcs/read/actions.c\
			srcs/read/buttons.c\
			srcs/read/history.c\
			srcs/read/read.c\
			srcs/read/syntax_color.c\
			srcs/read/termcap.c\
			srcs/read/autocomplete.c\
			srcs/read/t_options.c\
			srcs/read/parsing_man.c

HDRS	=	includes/msh.h

GCC		=	gcc -Wall -Werror -Wextra -O3

LIBS	=	-L /usr/lib/ -ltermcap

OBJS	=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(LIBS)

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all re fclean clean