/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:44:22 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 18:52:19 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	size_t			idx;

	psrc = (unsigned char *)src;
	pdst = (unsigned char *)dst;
	idx = 0;
	if (pdst < psrc && len)
	{
		while (idx < len)
		{
			pdst[idx] = psrc[idx];
			idx++;
		}
	}
	else if (pdst > psrc && len)
	{
		while (idx < len)
		{
			pdst[len - 1 - idx] = psrc[len - 1 - idx];
			idx++;
		}
	}
	return (dst);
}
