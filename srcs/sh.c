# include "../inc/minish.h"

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

static void reset(t_stat *stat)
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
			return ctrl_d();
		if (*input != '\0')
		{
			reset(stat);
			add_history(input);
			parsed = input_listing(input, stat);
			/*
			while (parsed)
			{
				printf("argc : %d\n", parsed->argc);
				printf("fdc : %d\n", parsed->argc);
				while (*parsed->argv)
					printf("[%s] ", *parsed->argv++);
				printf("\n");
				printf("cmd : [%s]\n", parsed->cmd);
				if (parsed->fdv)
				{
					printf("file : [%s]\n", parsed->fdv->file);
					printf("type : [%d]\n", parsed->fdv->type);
					printf("subtype : [%d]\n", parsed->fdv->subtype);
					printf("\n");
				}
				parsed = parsed->next;
				printf("\n");
			}*/

			if (TRUE)
				execute_line(&parsed, stat);
			while (del_node_front(&parsed, TRUE))
				;
			/**
			 * @brief : 최종 결과 = 실행 결과의 최종 값
			 * @retval : 이전 결과 값 && 또는 || 현재 결과 값, CMD && CMD 등 여러 명령 처리
			 */
			stat->last_ret = stat->cmd_ret;
		}
		free(input);
#ifdef LEAKS
		system("leaks minishell");
#endif
	}
	return (123);
}
