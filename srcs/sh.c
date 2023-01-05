/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:29:32 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 15:44:43 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static void	print_parse_err(t_elem *elems, t_stat *stat)
{
	char	*msg;

	msg = "syntax error near unexpected token";
	stat->cmd_ret = PARSE_ERROR;
	if (elems[stat->error].type == ET_PIP)
		ft_parsing_error(stat->pgname, msg, "|");
	else if (stat->error == 0)
		ft_parsing_error(stat->pgname, msg, "newline");
	else if (elems[stat->error - 1].type == ET_PIP)
		ft_parsing_error(stat->pgname, msg, "|");
	else if (elems[stat->error - 1].type == ET_STR)
		ft_parsing_error(stat->pgname, msg, "newline");
	else
		ft_parsing_error(stat->pgname, msg, elems[stat->error].data);
}

static void	reset(t_stat *stat)
{
	stat->pipe_num = 0;
	stat->error = -1;
}

int	minishell(t_stat *stat)
{
	char	*input;
	t_lst	*parsed;

	unset_echoctl();
	set_signal(SH_SHELL, SH_IGN);
	while (1)
	{
		input = readline("minishell % ");
		if (input == 0)
			return (ctrl_d());
		if (*input != '\0')
		{
			reset(stat);
			add_history(input);
			parsed = input_listing(input, stat);
			if (TRUE)
				execute_line(&parsed, stat);
			while (del_node_front(&parsed, TRUE))
				;
			stat->last_ret = stat->cmd_ret;
		}
		free(input);
	}
	return (123);
}
