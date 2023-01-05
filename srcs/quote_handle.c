/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:37:33 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:37:34 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static void	cp_without_quote(char *dst, char *src)
{
	int		i;
	char	quot;

	i = 0;
	while (*src)
	{
		if ((*src == '\'' || *src == '\"') && src[ft_quotelen(src)])
		{
			quot = *(src++);
			while (*src && quot != *src)
				dst[i++] = *(src++);
		}
		else
			dst[i++] = *src;
		src++;
	}
	dst[i] = 0;
}

int	quote_pairing(t_elem *elems)
{
	char	*bef;
	char	*aft;
	int		i;

	i = 0;
	while (elems[i].data)
	{
		bef = elems[i].data;
		aft = malloc(sizeof(char) * (ft_strlen(bef) + 1));
		if (aft == 0)
			return (1);
		cp_without_quote(aft, bef);
		elems[i].data = aft;
		free(bef);
		i++;
	}
	return (0);
}

int	ft_quotelen(const char *str)
{
	int		len;
	char	quote;

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
