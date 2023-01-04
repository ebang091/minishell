#include "../inc/minish.h"


static void	exit_numeric(char *arg, unsigned char error_number)
{
	//ft_builtin_error4(SHELL_NAME, "exit", arg, "numeric argument required");
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
	{
		// if (arg[ret] < '0' || arg[ret] > '9')
		// 	exit_numeric(arg, -1);
		// if ((sum * flag == -922337203685477580 && arg[ret] > '8')
		// 	|| (sum * flag == 922337203685477580 && arg[ret] > '7')
		// 	|| sum * flag <= -922337203685477581
		// 	|| sum * flag >= 922337203685477581)
		// 	exit_numeric(arg, -1);
		sum = sum * 10 + arg[ret] - '0';
	}
	exit(sum * flag);
}

int	ft_exit(const int argc, char **argv, t_stat *stat)
{
	
	write(2, "minishell exit\n", 15);
	if (argc > 2)
	{
		printf("%s %s %s",SHELL_NAME, "exit", "too many arguments");
		return (1);
	}
	if (argc == 1)
		exit(stat->last_ret);
	ft_exit_atoi(argv[1]);
	return (0);
}