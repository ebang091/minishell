/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:55:36 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 20:55:42 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/minish.h"

char	*ft_replace(char *str, int idx, int dellen, char *insert)
{
	int		insert_len;
	int		str_len;
	char	*ret;

	insert_len = ft_strlen(insert);
	str_len = ft_strlen(str);
	ret = (char *)malloc (sizeof (char) * (str_len + insert_len - dellen + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, str, idx + 1);
	ft_strlcpy(&ret[idx], insert, insert_len + 1);
	ft_strlcpy(&ret[idx + insert_len],
		&str[idx + dellen], str_len - idx - dellen + 1);
	return (ret);
}

/**
 * @brief copy arr's elem value
 * @param arr like envp
 * @return new arr
 */

char	**deep_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (arr[idx])
	{
		ret[idx] = (char *)malloc(sizeof(char) * (ft_strlen(arr[idx]) + 1));
		if (ret[idx] == 0)
			return (clean_content(ret, idx));
		ft_strlcpy(ret[idx], arr[idx], ft_strlen(arr[idx]) + 1);
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}

/**
 * copy arr's elem pointer
 * @param arr like envp
 * @return new arr
 */
char	**shallow_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!ret)
		return (0);
	idx = -1;
	while (arr[++idx])
		ret[idx] = arr[idx];
	ret[idx] = 0;
	return (ret);
}
