# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <zsh@duck.com>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 21:45:14 by youngpar          #+#    #+#              #
#    Updated: 2023/01/02 02:36:24 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libbuiltin.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

INCDIR	= -I ./include

DIR		= ./srcs
FILE	= cd.c \
			echo.c \
			env.c \
			env_utils.c \
			ft_itoa.c \
			ft_split.c \
			ft_utils.c \
			ft_utils2.c \
			ft_utils3.c \
			ft_print_error.c \
			pwd.c \
			var_handler.c \
			exit.c

SRCS	= $(addprefix $(DIR)/, $(FILE))
OBJS	= $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@make -C ../ recomp

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
