#include "../inc/include.h"
#include "../inc/minish.h"

int	ft_builtin_error(const char *cmd, const char *arg, const char *msg)
{
    write(2, cmd,ft_strlen(cmd));
    write(2, ": ", 2);
    write(2, arg, ft_strlen(arg));
    write(2, ": ", 2);
    write(2, msg, ft_strlen(msg));
    write(2, "\n",1);
    return (1);
}

int	ft_builtin_error4(const char *pgname, const char *cmd,
                         const char *arg, const char *msg)
{
    write(2, pgname, ft_strlen(pgname));
    write(2, ": ", 2);
    ft_builtin_error(cmd, arg, msg);
    return (1);
}
