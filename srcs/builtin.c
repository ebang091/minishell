/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:37:35 by ebang             #+#    #+#             */
/*   Updated: 2023/01/06 22:28:56 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

int	ft_env(char **env)
{
	if (!env)
		return (-1);
	while (*env)
		printf("%s\n", *env++);
	return (0);
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

int	ft_export(int argc, char **argv, char ***env)
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

int	ft_unset(int argc, char **argv, char ***env)
{
	if(argc == 1)
		return (0);
	if (argc > 1)
	{
		if (ft_rmenv(argv[1], env))
			return (-1);
		return (0);
	}
	return (-1);
}
