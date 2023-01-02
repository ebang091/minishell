#include "../inc/minish.h"

void	file_redirect_from(int idx, int *bef_fd, t_stat *stat)
{
	if (bef_fd[0] == 0)
	{
		if (idx == 0)
			dup2(stat->outFd, STDIN_FILENO);
	}
	else
	{
		dup2(bef_fd[0], STDIN_FILENO);
		close(bef_fd[0]);
	}
}

void	pipe_redirect_from(t_lst *node, int *pip_fd)
{
	if (node)
		dup2(pip_fd[0], STDIN_FILENO);
	close(pip_fd[0]);
}

void	out_redirect_to(t_lst *node, int *bef_fd, int *aft_fd, t_stat *stat)
{
	if (bef_fd[1] == 1)
	{
		if (node->next == 0)
			dup2(stat->inFd, STDOUT_FILENO);
		else
			dup2(aft_fd[1], STDOUT_FILENO);
	}
	else
	{
		dup2(bef_fd[1], STDOUT_FILENO);
		close(bef_fd[1]);
	}
	close(aft_fd[1]);
}