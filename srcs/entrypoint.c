/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entrypoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:49:04 by youngpar          #+#    #+#             */
/*   Updated: 2022/12/09 21:59:40 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

/**
 *	@brief: 실행 시 배너 출력
 */
static void	banner(t_stat *stat)
{
	printf("%s is running\n", stat->pgname);
}

static int	init(t_stat *stat, char **envp)
{
	stat->pgname = SHELL_NAME;
	stat->error = -1;
	stat->inFd = dup(STDIN_FILENO);
	stat->outFd = dup(STDOUT_FILENO);
	//stat->env = deep_copy(envp);
	//if (!(stat->env && stat->inFd != -1 && stat->outFd != -1))
	//	return (INIT_ERROR);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_stat	stat;

	if (argc != 1)
		return (-1);
	stat.error = init(&stat, envp);
	if (stat.error != INIT_ERROR)
	{
		banner(&stat);
		stat.error = minishell(&stat);
		printf("end\n");
	}
	return (0);
}
