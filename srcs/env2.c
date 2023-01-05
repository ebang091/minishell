/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:14:10 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 21:23:53 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

t_bool	ft_setenv(const char *key_value, char ***env)
{
	int		idx;
	char	*key;
	char	*tmp;

	key = key_finder(key_value, 0);
	if (key == 0)
		return (1);
	idx = index_of(key, *env);
	free(key);
	if ((*env)[idx] == 0)
		return (ft_putenv(key_value, env));
	tmp = ft_strdup(key_value);
	if (tmp == 0)
		return (1);
	free((*env)[idx]);
	(*env)[idx] = tmp;
	return (0);
}

int	index_of(const char *key, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env[++i])
	{
		j = -1;
		while (key[++j])
			if (env[i][j] != key[j])
				break ;
		if (env[i][j] == '=')
			return (i);
	}
	return (i);
}

char	*pointer_of(const char *key, char **env)
{
	int	index;

	index = index_of(key, env);
	return (env[index]);
}

char	*ft_getenv(const char *key, char **env)
{
	char	*ret;

	ret = pointer_of(key, env);
	if (ret == 0)
		return (0);
	while (*ret)
		if (*ret++ == '=')
			break ;
	return (ret);
}

t_bool	ft_putenv(const char *key_value, char ***env)
{
	int		size;
	int		idx;
	char	**new;

	size = 0;
	while ((*env)[size])
		size++;
	new = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new)
		return (1);
	idx = -1;
	while (++idx < size)
		new[idx] = (*env)[idx];
	new[idx] = ft_strdup(key_value);
	if (!new[idx])
	{
		while (--idx >= 0)
			free(new[idx]);
		free(new);
		return (1);
	}
	new[idx + 1] = 0;
	free(*env);
	*env = new;
	return (0);
}
