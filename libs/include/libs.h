#ifndef LIBS_H
# define LIBS_H

# include "pwd.h"
# include "env.h"

int	ft_cd(int argc, char **argv, char ***env);
int	ft_echo(int argc, char *argv[]);
int	ft_exit(const int argc, char **argv, t_stat *stat);

#endif
