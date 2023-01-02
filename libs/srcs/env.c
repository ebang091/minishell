#include "../../inc/minishell.h"

static t_bool	invalid_key(const char *key_value)
{
	int	idx;

	idx = -1;
	while (key_value[++idx])
	{
		if (key_value[idx] == '=')
			return (TRUE);
		if (key_value[idx] == '-')
		{
			ft_builtin_error_tok4(SHELL_NAME, "export",
				key_value, "not a valid identifier");
			break ;
		}
	}
	return (FALSE);
}

static int	ft_export_print(char **var)
{
	char	**p_env;
	char	*tmp;
	int		idx;
	int		cur;

	p_env = shallow_copy(var);
	if (p_env == NULL)
		return (-1);
	idx = -1;
	while (p_env[++idx])
	{
		cur = idx;
		while (p_env[++cur])
		{
			if (ft_strcmp(p_env[idx], p_env[cur]) > 0)
			{
				tmp = p_env[idx];
				p_env[idx] = p_env[cur];
				p_env[cur] = tmp;
			}
		}
		printf("declare -x %s\n", p_env[idx]);
	}
	free(p_env);
	return (0);
}

t_bool	ft_export(int argc, char **argv, char ***env)
{
	int	ret;
	int	idx;

	if (argc == 1)
		return (ft_export_print(*env));
	idx = 0;
	ret = 0;
	while (++idx < argc)
	{
		if (invalid_key(argv[idx]))
			ret += ft_setenv(argv[idx], env);
		else
			ret++;
	}
	return (0 < ret);
}

t_bool	ft_unset(int argc, char **argv, char ***env)
{
	int		idx;
	int		i;
	t_bool	ret;

	idx = 0;
	ret = 0;
	while (++idx < argc)
	{
		i = -1;
		while (argv[idx][++i])
		{
			if (argv[idx][i] == '-' || argv[idx][i] == '=')
			{
				ft_builtin_error_tok4(SHELL_NAME, "unset",
					argv[idx], "not a valid identifier");
				ret++;
				break ;
			}
		}
		if (argv[idx][i] == 0)
			ret += ft_rmenv(argv[idx], env);
	}
	return (0 < ret);
}

t_bool	ft_env(char **env)
{
	int	idx;

	idx = -1;
	while (env[++idx])
		printf("%s\n", env[idx]);
	return (0);
}
