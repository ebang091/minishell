/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:00:32 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/11 22:30:23 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;
	size_t			idx;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (ps1[idx] != ps2[idx])
			return (ps1[idx] - ps2[idx]);
		idx++;
	}
	return (0);
}
