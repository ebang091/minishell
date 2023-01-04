#include "../inc/minish.h"

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

t_bool	ft_setenv(const char *key_value, char ***env){

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

static char	*get_env_name(const char *str, int *len)
{
	char	*ret;

	*len = 1;
	if (str[*len] == '?')
		(*len)++;
	else
	{
		while ((str[*len] >= '0' && str[*len] <= '9')
			   || (str[*len] >= 'a' && str[*len] <= 'z')
			   || (str[*len] >= 'A' && str[*len] <= 'Z')
			   || str[*len] == '_')
			(*len)++;
	}
	if (*len > 1)
	{
		ret = malloc(sizeof(char) * (*len));
		if (ret == 0)
			return (0);
		ft_strlcpy(ret, &str[1], *len);
		return (ret);
	}
	else
		*len = 0;
	return (0);
}

static char	*get_variable(char *key, t_stat *stat)
{
	char	*ret;
	char	*value;

	if (key[0] == '?')
		value = ft_itoa(stat->last_ret);
	else
	{
		value = ft_getenv(key, stat->env);
		if (value == 0)
			value = "";
		value = ft_strdup(value);
	}
	ret = ft_strdup(value);
	free(value);
	return (ret);
}

static char	*env_replace(char *str, int *idx, t_stat *stat)
{
	int		env_klen;
	int		env_vlen;
	char	*env[2];
	char	*ret;

	env[0] = get_env_name(&str[*idx], &env_klen);
	if (env_klen == 0)
		return (str);
	if (env[0] == 0)
		return (0);
	env[1] = get_variable(env[0], stat);
	free(env[0]);
	if (env[1] == 0)
		return (0);
	ret = ft_replace(str, *idx, env_klen, env[1]);
	env_vlen = ft_strlen(env[1]);
	free(env[1]);
	if (ret == 0)
		return (0);
	free(str);
	*idx += env_vlen - 1;
	return (ret);
}

char	*env_setting(char *str, int nquote, t_stat *stat)
{
	char	quote;
	int		i;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (quote == 0 && (str[i] == '\'' || str[i] == '\"')
			&& str[i + ft_quotelen(&str[i])])
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else if ((quote != '\'' || nquote) && str[i] == '$')
		{
			str = env_replace(str, &i, stat);
			if (str == 0)
				return (0);
		}
		i++;
	}
	return (str);
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