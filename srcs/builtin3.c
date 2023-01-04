/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:01:00 by ebang             #+#    #+#             */
/*   Updated: 2023/01/04 22:01:04 by ebang            ###   ########.fr       */
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

int	ft_builtin_error4(char *pgname, char *cmd, char *arg, char *msg)
{
    write(2, pgname, ft_strlen(pgname));
    write(2, ": ", 2);
    ft_builtin_error(cmd, arg, msg);
    return (1);
}


int	ft_parsing_error(char *cmd, char *msg, char *tok)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" `", 2);
	ft_putstr_fd(tok, 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd("\n", 2);
	return (PARSE_ERROR);
}

int	ft_builtin_error_tok4(char *pgname,  char *cmd,
	char *tok, char *msg)
{
	ft_putstr_fd(pgname, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("`", 2);
	ft_putstr_fd(tok, 2);
	ft_putstr_fd("\'", 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}