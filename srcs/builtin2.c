#include "../inc/minish.h"

static void	exit_numeric(char *arg, unsigned char error_number)
{
	exit(error_number);
}

static void	ft_exit_atoi(char *arg)
{
	int			ret;
	int			flag;
	long long	sum;

	ret = -1;
	flag = 1;
	if (arg[0] == '+' || arg[0] == '-')
	{
		if (arg[0] == '-')
			flag = -1;
		ret = 0;
	}
	sum = 0;
	while (arg[++ret])
		sum = sum * 10 + arg[ret] - '0';
	exit(sum * flag);
}

int	ft_exit(const int argc, char **argv, t_stat *stat)
{
	write (2, "minishell exit\n", 15);
	if (argc > 2)
	{
		printf("%s %s %s", SHELL_NAME, "exit", "too many arguments");
		return (1);
	}
	if (argc == 1)
		exit(stat->last_ret);
	ft_exit_atoi(argv[1]);
	return (0);
}
