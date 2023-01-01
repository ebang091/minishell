#include "../include/util.h"
#include "../../inc/ft_errno.h"

void	ft_putstr_fd(int fd, const char *str)
{
	if (str)
		write(fd, str, ft_strlen(str));
}

int	ft_builtin_error(const char *cmd, const char *arg, const char *msg)
{
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, arg);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, "\n");
	return (1);
}

int	ft_builtin_error4(const char *pgname, const char *cmd,
	const char *arg, const char *msg)
{
	ft_putstr_fd(2, pgname);
	ft_putstr_fd(2, ": ");
	ft_builtin_error(cmd, arg, msg);
	return (1);
}

int	ft_parsing_error(const char *cmd, const char *msg, const char *tok)
{
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, " `");
	ft_putstr_fd(2, tok);
	ft_putstr_fd(2, "\'");
	ft_putstr_fd(2, "\n");
	return (PARS_ERR_RET);
}

int	ft_builtin_error_tok4(const char *pgname, const char *cmd,
	const char *tok, const char *msg)
{
	ft_putstr_fd(2, pgname);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, tok);
	ft_putstr_fd(2, "\'");
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, "\n");
	return (1);
}
