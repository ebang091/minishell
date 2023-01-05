/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_test2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:11:53 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:39:06 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"
#include "../inc/include.h"

int	cd_go_back(char ***env)
{
	char	*path;

	path = ft_getenv("OLDPWD", *env);
	if (!path)
	{
		ft_builtin_error4 ("minishell", "cd", "", "OLDPWD not set");
		return (0);
	}
	if (chdir(path) == -1)
	{
		return (0);
	}
	return (1);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
			i++;
	}
	return (str1[i] - str2[i]);
}
