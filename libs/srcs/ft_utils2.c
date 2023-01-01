#include "../../inc/minishell.h"

void	*clean_dchar(char **dchar, int cnt)
{
	int	i;

	if (dchar)
	{
		i = 0;
		while ((cnt == -1 && dchar[i]) || i < cnt)
		{
			free(dchar[i]);
			dchar[i] = 0;
			i++;
		}
		free(dchar);
	}
	return (0);
}

void	*clean_elem(t_elem *elems, int cnt)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (i < cnt)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}

void	*clean_fdv(t_fd *fdv, int fdc)
{
	int	i;

	if (fdv)
	{
		i = 0;
		while (i < fdc)
		{
			free(fdv[i].file);
			i++;
		}
		free(fdv);
	}
	return (0);
}

int	get_quote_len(const char *str)
{
	char	quote;
	int		len;

	quote = *str;
	if (quote == '\'' || quote == '\"')
	{
		len = 1;
		while (str[len] && quote != str[len])
			len++;
		return (len);
	}
	return (0);
}

void	ft_lowercase(char *str)
{
	int	i;

	if (str == 0)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
}
