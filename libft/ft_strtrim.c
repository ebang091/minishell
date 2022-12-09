/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:56:40 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/14 18:43:18 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	ft_isset(const char *set, int c)
{
	size_t	idx;
	size_t	len;

	len = ft_strlen(set);
	idx = 0;
	while (idx < len)
		if ((char)c == set[idx++])
			return (1);
	return (0);
}

static size_t	ft_begin(const char *s1, const char *set)
{
	size_t	begin;

	begin = 0;
	while (begin < ft_strlen(s1) && ft_isset(set, s1[begin]))
		begin++;
	return (begin);
}

static size_t	ft_end(const char *s1, const char *set)
{
	size_t	end;
	size_t	len;

	len = ft_strlen(s1);
	end = 0;
	while (end < len && ft_isset(set, s1[len - end - 1]))
		end++;
	return (len - end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ret;
	size_t		begin;
	size_t		end;
	size_t		idx;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(""));
	begin = ft_begin(s1, set);
	end = ft_end(s1, set);
	if (begin >= end)
		return (ft_strdup(""));
	idx = 0;
	ret = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!ret)
		return (0);
	while (begin < end)
		ret[idx++] = (char)s1[begin++];
	ret[idx] = 0;
	return (ret);
}
