#include "../inc/minish.h"

int	ft_find_option(char *argv)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	if (argv[0] != '-')
		return (0);
	while (argv[i] && argv[i] == 'n')
	{
			cnt++;
			i++;
	}
	if (argv[i])
		return (0);
	return (cnt);
}

void	ft_print_newline(int flag)
{
	if (!flag)
		printf("\n");
}

void	print_with_option(int start, int *flag, char *argv)
{
	if (start)
		*flag = 1;
	else
		printf("%s", argv);
}

int	ft_echo(int argc, char **argv)
{
	int	i;
	int	flag;
	int	start;

	i = 0;
	flag = 0;
	start = 1;
	while (++i < argc)
	{
		if (ft_find_option(argv[i]))
			print_with_option(start, &flag, argv[1]);
		else
		{
			printf("%s", argv[i]);
			if (i < argc -1)
				printf(" ");
			start = 0;
		}
	}
	ft_print_newline(flag);
	return (0);
}
