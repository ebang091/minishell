/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:36:55 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:36:56 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define BUFSIZE 1024;

# define TRUE	1
# define FALSE	0

# define ET_STR	4
# define ET_LTS	8
# define ET_GTS 16
# define ET_PIP 32
# define HEREDOC_RDBYTE	5
# define HEREDOC_TMP	"/tmp/minish_heredoc_tmp"

# define SH_IGN	-1
# define SH_DFL	0
# define SH_SHELL	1
# define SH_EXIT	3

/**
 *	@brief Error Number
 */
# define INIT_ERROR	9999
# define PARSE_ERROR 8888
# define EXEC_ERROR 7777
# define HEREDOC_TMPFILE "_heredoc"

typedef int		t_bool;

#endif
