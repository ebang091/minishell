#ifndef MINISH_H
# define MINISH_H

#include "include.h"
#include "struct.h"
#include "define.h"
#include "../libft/libft.h"

# define SHELL_NAME "minishell"

int	minishell(t_stat *stat);

/**
 * Signal Fuction
 */

void	unset_echoctl(void);
int 	ctrl_d(void);
void	set_signal(int n_int, int n_quit);


/**
 * Util
 */

char	*ft_replace(char *str, int idx, int dellen,char *insert);
int		ft_quotelen(const char *str);
char	**shallow_copy(char **arr);
char	**deep_copy(char **arr);

/**
 * Memory
 */

void	*ft_realloc(void *ptr, int before, int after);
void	*clean_fdv(t_fd *fdv, int fdc);
void	*clean_elem(t_elem *elems, int n);
void	*clean_content(char **arr, int n);


#endif	// MINISH_H
