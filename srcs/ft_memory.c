/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:55:33 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 20:55:34 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

void	*ft_realloc(void *ptr, int before, int after, t_bool is_free)
{
	void	*ret;

	ret = malloc(after);
	if (ret)
	{
		ret = ft_memset(ret, 0, after);
		if (ptr)
			ret = ft_memcpy(ret, ptr, before);
	}
	if (is_free)
		free(ptr);
	return (ret);
}

void	*clean_content(char **arr, int n)
{
	int	i;

	if (arr)
	{
		i = 0;
		while ((n == -1 && arr[i]) || i < n)
		{
			free(arr[i]);
			arr[i] = 0;
			i++;
		}
		free(arr);
	}
	return (0);
}

void	*clean_elem(t_elem *elems, int n)
{
	int	i;

	if (elems)
	{
		i = 0;
		while (i < n)
		{
			free(elems[i].data);
			i++;
		}
		free(elems);
	}
	return (0);
}

void	*clean_fdv(t_fd *fdv, int fdc)
{
	int	i;

	if (fdv)
	{
		i = 0;
		while (i < fdc)
		{
			free(fdv[i].file);
			i++;
		}
		free(fdv);
	}
	return (0);
}
