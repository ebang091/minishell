/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:28:23 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 23:29:14 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"
#ifndef HEREDOC_TMPFILE
	#define HEREDOC_TMPFILE "_heredoc"
#endif

int	redirect_from(t_fd *fd, t_stat *stat)
{
	int		fd_in;
	int		ret;

	if (fd->subtype == 1)
		fd_in = open(fd->file, O_RDONLY | O_EXCL);
	else
	{
		ret = heredoc(fd, stat);
		stat->cmd_ret = ret;
		if (ret == 1)
			return (-2);
		if (ret != 0)
			return (-1);
		stat->exist_tmp = 1;
		fd_in = open(HEREDOC_TMPFILE, O_RDONLY | O_EXCL);
	}
	return (fd_in);
}

int	redirect_to(t_fd *fd)
{
	int	fd_out;

	if (fd->subtype == 1)
		fd_out = open(fd->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd_out = open(fd->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (fd_out);
}

int	redirect(t_lst *node, int *bef_fd, t_stat *stat)
{
	int	i;

	bef_fd[1] = 1;
	bef_fd[0] = 0;
	i = -1;
	while (++i < node->fdc)
	{
		if (node->fdv[i].type == ET_GTS)
		{
			if (bef_fd[1] != STDOUT_FILENO)
				close(bef_fd[1]);
			bef_fd[1] = redirect_to(&node->fdv[i]);
		}
		if (node->fdv[i].type == ET_LTS)
		{
			if (bef_fd[0] != STDIN_FILENO)
				close(bef_fd[0]);
			bef_fd[0] = redirect_from(&node->fdv[i], stat);
		}
		if (bef_fd[0] == -2)
			return (-2);
		if (bef_fd[1] == -1 || bef_fd[0] == -1)
			return (i);
	}
	return (-1);
}
