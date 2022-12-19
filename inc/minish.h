#ifndef MINISH_H
# define MINISH_H

#include "include.h"
#include "struct.h"
#include "define.h"

# define SHELL_NAME "minishell"

int	minishell(t_stat *stat);

/**
 * Signal Fuction
 */

void	unset_echoctl(void);
int 	ctrl_d(void);
void	set_signal(int n_int, int n_quit);

#endif	// MINISH_H
