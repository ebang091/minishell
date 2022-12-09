/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:23:16 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/08 03:27:13 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*ps;

	idx = 0;
	ps = (unsigned char *)s;
	while (idx < n)
	{
		if (ps[idx] == (unsigned char)c)
			return (&ps[idx]);
		idx++;
	}
	return ((void *)0);
}
