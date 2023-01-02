#include <stdio.h>
#include "../../inc/structure.h"

static t_bool	is_newline(const char *str)
{
	int		idx;
	int		n_cnt;

	idx = 1;
	n_cnt = 0;
	if (str[0] != '-')
		return (FALSE);
	while (str[idx] && str[idx] == 'n')
	{
		n_cnt++;
		idx++;
	}
	return (0 < n_cnt);
}

int	ft_echo(int argc, char *argv[])
{
	int		idx;
	t_bool	nl;

	idx = 0;
	nl = FALSE;
	while (++idx < argc)
	{
		if (is_newline(argv[idx]))
			nl = TRUE;
		else
		{
			printf("%s", argv[idx]);
			if (idx < argc - 1)
				printf(" ");
		}
	}
	if (nl == FALSE)
		printf("\n");
	return (0);
}
