# include "../inc/minish.h"
//hi
int	minishell(t_stat *stat)
{
	char	*input;
	t_lst	*parsed;

	stat->pipe_num = 0;
	stat->error = -1;

	while (1)
	{
		printf("%s", stat->pgname);
		input = readline(" % ");
		//if (!input)
		//	return (
		if (*input != '\0')
		{
			stat->pipe_num = 0;
			stat->error = -1;
			printf("[%s]\n", input);
		}
		free(input);
	}
	return (123);
}
