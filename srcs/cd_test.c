/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:09:02 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:38:45 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"
#include "../inc/include.h"

static char	*cd_find_path(int argc, char **argv)
{
	int	i;

	i = -1;
	if ((argc > 1 && !ft_strcmp(argv[1], "--")))
		return (argv[2]);
	if (argc == 1)
		return (NULL);
	while (*argv[++i] != 0)
	{
		if (argv[i][0] == 'c' && argv[i][1] == 'd')
			break ;
	}
	i++;
	return (argv[i]);
}

int	ft_free(char *str, int flag)
{
	free(str);
	if (flag)
		return (ft_builtin_error(SHELL_NAME, "cd", "HOME not set"));
	else
		return (-1);
}

int	ft_set_pwd(char ***env)
{
	char	*path[2];

	path[0] = ft_getenv("PWD", *env);
	if (!path[0])
		path[0] = "";
	path[1] = ft_strjoin("OLDPWD=", path[0]);
	if (!path[1])
		return (1);
	if (ft_setenv(path[1], env))
		return (ft_free(path[1], 0));
	free(path[1]);
	path[0] = getcwd(0, 0);
	if (!path[0])
		return (ft_free(path[0], 1));
	path[1] = ft_strjoin("PWD=", path[0]);
	free(path[0]);
	if (ft_setenv(path[1], env))
		return (ft_free(path[1], 0));
	free(path[1]);
	return (0);
}

int	cd_go_home(char ***env)
{
	char	*path;

	path = ft_getenv("HOME", *env);
	if (!path)
	{
		ft_builtin_error4 ("minishell", "cd", "", strerror(errno));
		return (0);
	}
	if (chdir(path) == -1)
		return (0);
	return (1);
}

int	ft_cd(int argc, char **argv, char ***env)
{
	int		ret;
	char	*path;

	ret = 0;
	path = cd_find_path(argc, argv);
	if (!path)
	{
		if (!cd_go_home(env))
			return (-1);
	}
	else if (!strcmp(path, "-"))
	{
		if (!cd_go_back(env))
			return (-1);
	}
	else if (chdir(path))
	{
		ft_builtin_error4("minishell", "cd", path, "no such file or directory");
		return (-1);
	}
	ret = ft_set_pwd(env);
	return (ret);
}
