/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:30:25 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 21:30:28 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"
#include "../inc/minish.h"

int	ft_builtin_error(const char *cmd, const char *arg, const char *msg)
{
    write(2, cmd,ft_strlen(cmd));
    write(2, ": ", 2);
    write(2, arg, ft_strlen(arg));
    write(2, ": ", 2);
    write(2, msg, ft_strlen(msg));
    write(2, "\n",1);
    return (1);
}

int	ft_builtin_error4(const char *pgname, const char *cmd, const char *arg, const char *msg)
{
    write(2, pgname, ft_strlen(pgname));
    write(2, ": ", 2);
    ft_builtin_error(cmd, arg, msg);
    return (1);
}


int	ft_parsing_error(const char *cmd, const char *msg, const char *tok)
{
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, " `");
	ft_putstr_fd(2, tok);
	ft_putstr_fd(2, "\'");
	ft_putstr_fd(2, "\n");
	return (PARSE_ERROR);
}

int	ft_builtin_error_tok4(const char *pgname, const char *cmd,
	const char *tok, const char *msg)
{
	ft_putstr_fd(2, pgname);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, cmd);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, "`");
	ft_putstr_fd(2, tok);
	ft_putstr_fd(2, "\'");
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, msg);
	ft_putstr_fd(2, "\n");
	return (1);
}