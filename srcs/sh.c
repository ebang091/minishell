# include "../inc/minish.h"

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
			while (parsed)
			{
				while (*parsed->argv)
					printf("[%s] ", *parsed->argv++);
				parsed = parsed->next;
				printf("\n");
			}
			//	TODO : 파싱

			//	TODO : 실행 or 에러 처리
			//	TODO : 파싱 자료구조 release

			/**
			 * @brief : 최종 결과 = 실행 결과의 최종 값
			 * @retval : 이전 결과 값 && 또는 || 현재 결과 값, CMD && CMD 등 여러 명령 처리
			 */
			stat->last_ret = stat->cmd_ret;
		}
		free(input);
	}
	return (123);
}
