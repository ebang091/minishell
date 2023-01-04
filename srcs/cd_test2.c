/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_test2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:11:53 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 23:12:28 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"
#include "../inc/include.h"

int	cd_go_back(char ***env)
{
	char	*path;

	path = ft_getenv("OLDPWD", *env);
	printf("path : %s\n", path);
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
