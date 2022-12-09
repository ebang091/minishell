# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngpar@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 12:44:14 by youngpar          #+#    #+#              #
#    Updated: 2022/12/09 21:10:28 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isascii.c	\
	   ft_strlcat.c	\
	   ft_isalnum.c	\
	   ft_isdigit.c	\
	   ft_strlcpy.c	\
	   ft_isalpha.c	\
	   ft_isprint.c	\
	   ft_strlen.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strncmp.c \
	   ft_strchr.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_strrchr.c \
	   ft_strdup.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_memccpy.c \
	   ft_memcpy.c \
	   ft_memchr.c \
	   ft_memmove.c \
	   ft_memcmp.c \
	   ft_itoa.c \
	   ft_split.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_strmapi.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_putendl_fd.c \
	   ft_abs.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstadd_back.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstclear.c \
	   ft_lstmap.c \
	   ft_isspace.c

OBJECTS = $(SRCS:.c=.o)

INC = -I .

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJECTS)
fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : all clean fclean re
