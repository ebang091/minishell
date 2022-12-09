/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:29:08 by youngpar          #+#    #+#             */
/*   Updated: 2021/12/11 22:09:59 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 0x20)
		return (0x20);
	if (c == 0x09)
		return (0x09);
	if (c == 0x0a)
		return (0x0a);
	if (c == 0x0b)
		return (0x0b);
	if (c == 0x0c)
		return (0x0c);
	if (c == 0x0d)
		return (0x0d);
	return (0);
}
