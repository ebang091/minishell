/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:37:38 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 18:45:44 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

// static void	exit_numeric(char *arg, unsigned char error_number)
// {
// 	ft_builtin_error4("minishell", "exit", arg, "numeric argument required");
// 	exit(error_number);
// }

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
	if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	write (2, "minishell exit\n", 15);
	if (argc == 1)
		exit(stat->last_ret);
	ft_exit_atoi(argv[1]);
	return (0);
}
