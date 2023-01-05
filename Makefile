NAME	= minishell
CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror 

LIB		= libft.a

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
		  echo.c \
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
		  env2.c \
		  env3.c \
		  redirect.c \
		  fd_setter.c \
		  heredoc.c \
		  cd_test.c \
		  cd_test2.c \
		  execute.c \
		  execute2.c


SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS	= $(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

all		: $(NAME) 

$(NAME)	: $(OBJS) $(LIB)
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
