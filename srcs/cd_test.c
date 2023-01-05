/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:09:02 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 16:13:54 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"
#include "../inc/include.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
			i++;
	}
	return (str1[i] - str2[i]);
}

char	*find_path(char **argv)
{
	int	i;

	i = -1;
	while (*argv[++i] != 0)
	{
		if (argv[i][0] == 'c' && argv[i][1] == 'd')
			break ;
	}
	i++;
	return (argv[i]);
}

int	ft_set_pwd(char ***env)
{
	char	*path;

	path = ft_getenv("PWD", *env);
	if (!path)
		path = "";
	path = ft_strjoin("OLDPWD=", path);
	if (ft_setenv(path, env))
		return (-1);
	path = getcwd(0, 0);
	if (!path)
		return (ft_builtin_error(SHELL_NAME, "cd", "HOME not set"));
	path = ft_strjoin("PWD=", path);
	if (ft_setenv(path, env))
		return (-1);
	free(path);
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

	path = find_path(argv);
	if (!ft_strcmp(path, "") || !strcmp(path, "--"))
	{
		if (!cd_go_home(env))
			return (-1);
	}
	else if (!strcmp(path, "-"))
	{
		if (!cd_go_back(env))
			return (-1);
	}
	else
	{
		if (chdir(path))
			ft_builtin_error("cd", "no such file or directory", path);
	}
	ret = ft_set_pwd(env);
	return (ret);
}
