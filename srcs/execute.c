/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:21:56 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:37:54 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static int	ft_strcmp_igcase(char *s1, char *s2)
{
	int		i;
	char	c;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i])
	{
		c = s1[i];
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			c = s1[i] - 'A' + 'a';
		if (c != s2[i])
			return (c - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*find_path(char *cmd, t_stat *stat)
{
	char	**split_path;
	int		i;
	char	*path;
	char	*pathapp;

	split_path = ft_split(ft_getenv("PATH", stat->env), ':');
	if (split_path == 0)
		return (0);
	i = -1;
	while (split_path[++i])
	{
		path = ft_strjoin(split_path[i], "/");
		pathapp = ft_strjoin(path, cmd);
		free(path);
		if (pathapp == 0)
			return (clean_content(split_path, -1));
		if (open(pathapp, O_EXCL) != -1)
		{
			clean_content(split_path, -1);
			return (pathapp);
		}
		free(pathapp);
	}
	clean_content(split_path, -1);
	return (cmd);
}

int	exec_builtin(t_lst *node, t_stat *stat)
{
	if (ft_strcmp_igcase(node->cmd, "echo") == 0)
		return (ft_echo(node->argc, node->argv));
	if (ft_strcmp_igcase(node->cmd, "pwd") == 0)
		return (ft_pwd(stat->env));
	else if (ft_strcmp_igcase(node->cmd, "env") == 0)
		return (ft_env(stat->env));
	else if (ft_strcmp_igcase(node->cmd, "cd") == 0)
		return (stat->pipe_num == 0
			&& ft_cd(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "export") == 0)
		return (stat->pipe_num == 0
			&& ft_export(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "unset") == 0)
		return (stat->pipe_num == 0
			&& ft_unset(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "exit") == 0)
		return (stat->pipe_num == 0
			&& ft_exit(node->argc, node->argv, stat));
	return (-1);
}
