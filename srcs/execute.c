/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:21:56 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 23:24:59 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static void	print_fdopen_err(char *file, t_stat *stat)
{
	char	*msg;

	msg = strerror(errno);
	ft_builtin_error(stat->pgname, file, msg);
	stat->cmd_ret = EXEC_ERROR;
}

static void	print_exec_err(int i, char *cmd, t_stat *stat)
{
	char	*msg;

	if (i == ft_strlen(cmd))
		msg = "command not found";
	else
		msg = strerror(errno);
	ft_builtin_error(stat->pgname, cmd, msg);
}

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

static char	*find_path(char *cmd, t_stat *stat)
{
	char	**split_path;
	int		i;
	char	*path;
	char	*pathapp;

	split_path = ft_split(ft_getenv("PATH", stat->env), ':');
	if (split_path == 0)
		return (0);
	i = 0;
	while (split_path[i++])
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

static int	exec_builtin(t_lst *node, t_stat *stat)
{
	if (ft_strcmp_igcase(node->cmd, "echo") == 0)
		return (ft_echo(node->argc, node->argv));
	if (ft_strcmp_igcase(node->cmd, "pwd") == 0)
		return (ft_pwd());
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

static int	execute(t_lst *input, t_stat *stat)
{
	int	ret;

	ret = exec_builtin(input, stat);
	if (ret == -1)
		ret = exec_program(input, stat);
	return (ret);
}

int	exec_program(t_lst *node, t_stat *stat)
{
	pid_t	pid;
	int		fork_ret;
	int		i;

	fork_ret = 0;
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (node->cmd[i] && node->cmd[i] != '/')
			i++;
		if ((size_t)i == ft_strlen(node->cmd))
			node->cmd = find_path(node->cmd, stat);
		execve(node->cmd, node->argv, stat->env);
		//print_exec_err(i, node->cmd, stat);
		write(2, "minishell: ", 11);
		write(2, node->cmd, ft_strlen(node->cmd));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 2);
		exit(EXEC_ERROR);
	}
	set_signal(SH_IGN, SH_IGN);
	wait(&fork_ret);
	set_signal(SH_SHELL, SH_IGN);
	return (fork_ret >> 8);
}

int	execute_line(t_lst **input, t_stat *stat)
{
	int	bef_fd[2];
	int	pip_fd[2];
	int	fd_err_idx;
	int	i;

	i = 0;
	while (*input && stat->cmd_ret != -1)
	{
		pipe(pip_fd);
		fd_err_idx = redirect(*input, bef_fd, stat);
		if (fd_err_idx == -2)
			return (1);
		if (fd_err_idx != -1)
			perror("OPEN ERROR");
			//print_fdopen_err((*input)->fdv[fd_err_idx].file, stat);
		file_redirect_from(i++, bef_fd, stat);
		out_redirect_to(*input, bef_fd, pip_fd, stat);
		if (fd_err_idx == -1 && (*input)->cmd && ft_strlen((*input)->cmd))
			stat->cmd_ret = execute(*input, stat);
		rm_heredoc_tmpfile(stat);
		dup2(stat->inFd, STDIN_FILENO);
		dup2(stat->outFd, STDOUT_FILENO);
		del_node_front(input, TRUE);
		pipe_redirect_from(*input, pip_fd);
	}
	return (0);
}