/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:23:22 by youngpar          #+#    #+#             */
/*   Updated: 2021/05/10 19:03:57 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long		sn;

	sn = n;
	if (sn < 0)
	{
		write(fd, "-", 1);
		sn *= -1;
	}
	if (sn >= 10)
		ft_putnbr_fd((int)(sn / 10), fd);
	ft_putchar_fd(sn % 10 + '0', fd);
}
