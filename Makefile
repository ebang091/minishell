NAME	= minishell
CC		= cc -g
# CFLAGS	= -Wall -Wextra -Werror 

LIB		= libft.a

#RLDIR	= /opt/homebrew/opt/readline
#RLDIR	= ~/.brew/opt/readline
RLDIR	= ~/brew/opt/readline

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
		  signal2.c \
		  builtin.c \
		  builtin2.c \
		  builtin3.c \
		  ft_memory.c \
		  ft_util.c \
		  listing.c \
		  parsing.c \
		  quote_handle.c \
		  exception.c \
		  env.c \
		  redirect.c \
		  fd_setter.c \
		  heredoc.c \
		  cd.c \
		  execute.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS	= $(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(LIB) $(NAME)

test	: $(OBJS)
	$(CC) -D TEST $(CFLAGS) $(OBJS) $(LIBDIR) $(LDLIBS) -o $(NAME)

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
