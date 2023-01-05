/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:39:31 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:39:40 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_elem	t_elem;
typedef struct s_fd		t_fd;
typedef struct s_lst	t_lst;
typedef struct s_stat	t_stat;

struct	s_elem
{
	char	*data;
	int		type;
	int		subtype;
};

struct	s_fd
{
	char	*file;
	int		type;
	int		subtype;
};

struct	s_lst
{
	char	*cmd;
	int		argc;
	char	**argv;
	int		fdc;
	t_fd	*fdv;
	t_lst	*next;
};

struct	s_stat
{
	char	*pgname;
	int		in_fd;
	int		out_fd;
	int		exist_tmp;
	int		cmd_ret;
	int		last_ret;
	int		pipe_num;
	int		error;

	char	**env;
};

#endif	//STRUCT_H
