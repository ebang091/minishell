/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:55:27 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:37:42 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static void	print_exec_err(int i, char *cmd, t_stat *stat)
{
	char	*msg;

	if ((size_t)i == ft_strlen(cmd))
	{
		msg = "command not found";
		stat->error = 127;
	}
	else
		msg = strerror(errno);
	ft_builtin_error(stat->pgname, cmd, msg);
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
		print_exec_err(i, node->cmd, stat);
		exit(stat->error);
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
			print_fdopen_err((*input)->fdv[fd_err_idx].file, stat);
		file_redirect_from(i++, bef_fd, stat);
		out_redirect_to(*input, bef_fd, pip_fd, stat);
		if (fd_err_idx == -1 && (*input)->cmd && ft_strlen((*input)->cmd))
			stat->cmd_ret = execute(*input, stat);
		rm_heredoc_tmpfile(stat);
		dup2(stat->in_fd, STDIN_FILENO);
		dup2(stat->out_fd, STDOUT_FILENO);
		del_node_front(input, TRUE);
		pipe_redirect_from(*input, pip_fd);
	}
	return (0);
}

int	execute(t_lst *input, t_stat *stat)
{
	int	ret;

	ret = exec_builtin(input, stat);
	if (ret == -1)
		ret = exec_program(input, stat);
	return (ret);
}
