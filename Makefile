NAME	= minishell
CC		= cc
#CFLAGS	= -Wall -Wextra -Werror

LIB		= libft.a

RLDIR	= /opt/homebrew/opt/readline
#RLDIR	= ~/.brew/opt/readline

RLINC	= $(RLDIR)/include

LIBDIR	= -L $(RLDIR)/lib \
		  -L libft
LDLIBS	= -l readline \
		  -l ft
INCDIR	= -I inc \
		  -I $(RLINC)

SRCDIR	= srcs
SRCFILE	= entrypoint.c \
		  sh.c \
		  signal.c \
		  ft_memory.c \
		  ft_util.c \
		  listing.c \
		  parsing.c \
		  parsing2.c \
		  quote_handle.c \
		  exception.c \
		  env.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS	= $(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDIR) $(LDLIBS) -o $(NAME)

$(LIB)	:
	@make -C libft

clean	:
	@rm -rf $(OBJS)
	@make -C libft clean

fclean	: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re		: fclean all

.PHONY	: all clean fclean re
