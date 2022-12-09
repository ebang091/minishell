/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:25:58 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/11 22:22:37 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ys_isspace(int c)
{
	if (c == 0x20)
		return (0x20);
	if (c == 0x09)
		return (0x09);
	if (c == 0x0a)
		return (0x0a);
	if (c == 0x0b)
		return (0x0b);
	if (c == 0x0c)
		return (0x0c);
	if (c == 0x0d)
		return (0x0d);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			flag;
	long long	ret;

	flag = 1;
	ret = 0;
	while (ys_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (ret * 10 + *str - '0' > 2147483647 && flag == 1)
			return (-1);
		else if (ret * 10 + *str - '0' > 2147483648 && flag == -1)
			return (0);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return ((int)(ret * flag));
}
