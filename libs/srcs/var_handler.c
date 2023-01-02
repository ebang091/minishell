#include "../include/util.h"
#include "../include/env.h"


static char	*key_finder(const char *key_value, int idx)
{
	char	*ret;

	if (key_value[idx] == 0)
		return (0);
	if (key_value[idx] == '=')
	{
		ret = (char *)malloc(sizeof(char) * (idx + 1));
		ret[idx] = 0;
		return (ret);
	}
	ret = key_finder(key_value, idx + 1);
	if (!ret)
		return (0);
	ret[idx] = key_value[idx];
	return (ret);
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
