/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:37:06 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 22:38:58 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include "include.h"
# include "struct.h"
# include "define.h"
# include "../libft/libft.h"

# define SHELL_NAME "minishell"

// # define TEST	//	TODO : 주석 처리하면 출력 사라짐
// # define LEAKS	//	TODO : 주석 처리하면 LEAKS 출력 사라짐
int		minishell(t_stat *stat);

/**
 * Signal Fuction
 */

void	do_nothing(void);
void	unset_echoctl(void);
int		ctrl_d(void);
void	set_signal(int n_int, int n_quit);
void	set_struct(struct sigaction *act, void (*f)(int));

/**
 * Util
 */

char	*ft_replace(char *str, int idx, int dellen, char *insert);
int		ft_quotelen(const char *str);
char	**shallow_copy(char **arr);
char	**deep_copy(char **arr);
int		ft_strcmp(char *str1, char *str2);

/**
 * Memory
 */

void	*ft_realloc(void *ptr, int before, int after, t_bool is_free);
void	*clean_fdv(t_fd *fdv, int fdc);
void	*clean_elem(t_elem *elems, int n);
void	*clean_content(char **arr, int n);

/**
 * Parsing
 */

t_lst	*input_listing(char *input, t_stat *stat);
t_elem	*tokenizing(const char *str, int *cnt, t_stat *stat);
int		quote_pairing(t_elem *elems);
int		listing(t_elem *elems, int elem_cnt, t_lst **lst);
int		add_node_back(t_lst **head, t_lst *node);
int		del_node_front(t_lst **head, int is_deep_copied);

/**
 * Env
 */

int		str_to_env(t_elem *elems, t_stat *stat);
char	*env_setting(char *str, int nquote, t_stat *stat);
char	*ft_getenv(const char *key, char **env);
t_bool	ft_setenv(const char *key_value, char ***env);
t_bool	ft_rmenv(const char *key, char ***env);
t_bool	ft_putenv(const char *key_value, char ***env);
char	*key_finder(const char *key_value, int idx);

/**
 * Exception
 */

int		parsing_error(t_elem *elems, t_stat *stat);
void	print_parse_err(t_elem *elems, t_stat *stat);
void	print_fdopen_err(char *file, t_stat *stat);

/**
 * Heredoc
 */

int		heredoc(t_fd *fd, t_stat *stat);
void	rm_heredoc_tmpfile(t_stat *stat);
char	*heredoc_input(char *eof, t_stat *stat);

/**
 * Redirect
 */

void	file_redirect_from(int idx, int *bef_fd, t_stat *stat);
void	pipe_redirect_from(t_lst *node, int *pip_fd);
void	out_redirect_to(t_lst *node, int *bef_fd, int *aft_fd, t_stat *stat);
int		redirect(t_lst *node, int *bef_fd, t_stat *stat);
int		redirect_to(t_fd *fd);
int		redirect_from(t_fd *fd, t_stat *stat);

/**
 * Exec
 */
int		exec_builtin(t_lst *node, t_stat *stat);
int		execute_line(t_lst **input, t_stat *stat);
int		exec_program(t_lst *node, t_stat *stat);
int		execute(t_lst *input, t_stat *stat);
char	*find_path(char *cmd, t_stat *stat);

/**
 * builtin
*/

//env
int		ft_env(char **env);
int		ft_export(int argc, char **argv, char ***env);
int		ft_unset(int argc, char **argv, char ***env);
int		ft_pwd(char **env);
char	*key_finder(const char *key_value, int idx);
int		index_of(const char *key, char **env);
char	*pointer_of(const char *key, char **env);

//exit
int		ft_exit(const int argc, char **argv, t_stat *stat);

//cd
int		ft_cd(int argc, char **argv, char ***env);
int		cd_go_back(char ***env);

//echo
int		ft_echo(int argc, char **argv);

//error
int		ft_builtin_error(const char *cmd, const char *arg, const char *msg);
int		ft_builtin_error4(char *pgname, char *cmd, char *arg, char *msg);
int		ft_parsing_error(char *cmd, char *msg, char *tok);
int		ft_strcmp(char *str1, char *str2);
int		ft_builtin_error_tok4(char *pgname, char *cmd,
			const char *tok, char *msg);
#endif
