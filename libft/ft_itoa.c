/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 17:04:02 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 19:01:41 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(long long buf)
{
	size_t	size;

	size = 0;
	while (buf)
	{
		buf /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t			size;
	size_t			idx;
	long long		buf;
	char			*cbuf;

	buf = (long long)n;
	if (n < 0)
		buf *= -1;
	size = ft_numlen(buf);
	if (n <= 0)
		size++;
	cbuf = (char *)malloc(sizeof(char) * (size + 1));
	if (!cbuf)
		return ((void *)0);
	idx = 0;
	while (idx < size)
	{
		cbuf[size - idx++ - 1] = buf % 10 + '0';
		buf /= 10;
	}
	if (n < 0)
		cbuf[0] = '-';
	cbuf[size] = 0;
	return (cbuf);
}
