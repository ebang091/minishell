#ifndef ENV_H
# define ENV_H

# include "../../inc/minish.h"
t_bool	ft_env(char **env);
t_bool	ft_export(int argc, char **argv, char ***env);
t_bool	ft_unset(int argc, char **argv, char ***env);

#endif
