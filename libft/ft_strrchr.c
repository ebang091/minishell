/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:52:22 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/07 23:21:01 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		*ret;

	ret = NULL;
	len = 0;
	while (s[len])
	{
		if (s[len] == (char)c)
			ret = (char *)&s[len];
		len++;
	}
	if (s[len] == (char)c)
		ret = (char *)&s[len];
	return (ret);
}
