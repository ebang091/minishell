/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:18:59 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 23:20:33 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

t_bool	ft_rmenv(const char *key, char ***env)
{
	char	**new;
	int		rmidx;
	int		idx;
	int		size;

	if (pointer_of(key, *env) == 0)
		return (0);
	rmidx = index_of(key, *env);
	size = 0;
	while ((*env)[size])
		size++;
	new = (char **)malloc(sizeof(char *) * size);
	if (!new)
		return (1);
	idx = -1;
	while (++idx < rmidx)
		new[idx] = (*env)[idx];
	free((*env)[idx--]);
	while ((*env)[++idx + 1])
		new[idx] = (*env)[idx + 1];
	new[idx] = 0;
	free(*env);
	*env = new;
	return (0);
}

int	str_to_env(t_elem *elems, t_stat *stat)
{
	int		i;
	char	*ret;

	i = 0;
	while (elems[i].data)
	{
		if (elems[i].type == ET_STR)
		{
			ret = env_setting(elems[i].data, 0, stat);
			if (ret == 0)
				return (1);
			elems[i].data = ret;
		}
		i++;
	}
	return (0);
}
