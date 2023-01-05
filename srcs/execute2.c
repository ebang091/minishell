#include "../inc/minish.h"

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
		dup2(stat->in_fd, STDIN_FILENO);
		dup2(stat->out_fd, STDOUT_FILENO);
		del_node_front(input, TRUE);
		pipe_redirect_from(*input, pip_fd);
	}
	return (0);
}
