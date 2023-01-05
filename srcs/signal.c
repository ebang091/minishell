/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebang <ebang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:38:16 by ebang             #+#    #+#             */
/*   Updated: 2023/01/05 16:38:17 by ebang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	signal_handler_exit(int signo)
{
	if (signo == SIGINT)
		exit(1);
}

void	unset_echoctl(void)
{
	struct termios	term;

	tcgetattr (STDOUT_FILENO, &term);
	term.c_lflag &= (~ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &term);
}

int	ctrl_d(void)
{
	printf("\x1b[1A");
	rl_on_new_line();
	rl_redisplay();
	printf("exit\n");
	return (1);
}

void	set_signal(int n_int, int n_quit)
{
	struct sigaction	act_ignore;
	struct sigaction	act_handler;
	struct sigaction	act_exit;

	set_struct(&act_ignore, SIG_IGN);
	set_struct(&act_handler, signal_handler);
	set_struct(&act_exit, signal_handler_exit);
	if (n_int == SH_IGN)
		sigaction(SIGINT, &act_ignore, NULL);
	if (n_int == SH_DFL)
		sigaction(SIGINT, &act_ignore, NULL);
	if (n_int == SH_SHELL)
		sigaction(SIGINT, &act_handler, NULL);
	if (n_int == SH_EXIT)
		sigaction(SIGINT, &act_exit, NULL);
	if (n_quit == SH_IGN)
		sigaction(SIGQUIT, &act_ignore, NULL);
	if (n_quit == SH_DFL)
		sigaction(SIGQUIT, &act_ignore, NULL);
	if (n_quit == SH_SHELL)
		sigaction(SIGQUIT, &act_handler, NULL);
}
