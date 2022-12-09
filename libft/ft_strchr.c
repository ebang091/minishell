/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:48:15 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/08 16:14:50 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			len;
	size_t			idx;
	unsigned char	*cs;

	cs = (unsigned char *)s;
	idx = 0;
	len = ft_strlen(s);
	while (idx < len)
	{
		if (cs[idx] == (unsigned char)c)
			return ((char *)&cs[idx]);
		idx++;
	}
	if (cs[idx] == (unsigned char)c)
		return ((char *)&cs[idx]);
	return (0);
}
