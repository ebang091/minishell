/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:03:50 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/08 03:13:50 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			idx;

	idx = 0;
	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (idx < n)
	{
		pdst[idx] = psrc[idx];
		idx++;
	}
	return (dst);
}
