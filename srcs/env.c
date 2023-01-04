/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:15:42 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 23:19:45 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
