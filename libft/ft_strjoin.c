/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:14:26 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/11 22:37:08 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		idx;
	size_t		ss;

	idx = 0;
	if (!s1 || !s2)
		return ((void *)0);
	ss = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (1 + ss + ft_strlen(s2)));
	if (!s3)
		return ((void *)0);
	while (s1[idx])
	{
		s3[idx] = s1[idx];
		idx++;
	}
	while (*s2)
		s3[idx++] = *s2++;
	s3[idx] = 0;
	return (s3);
}
