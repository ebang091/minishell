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
	struct	termios	term;

	tcgetattr(STDOUT_FILENO, &term);	//	현재 터미널 정보를 term에 저장
	term.c_cflag &= (~ECHOCTL);			//	터미널의 로컬 플래그를 제어문자 (^C, ^D, ...) 출력 가능하게 변경
	tcsetattr(STDOUT_FILENO, TCSANOW, &term);
}

int		ctrl_d(void)
{
	printf("\x1b[1A");
	rl_on_new_line();
	rl_redisplay();
	printf("exit\n");
	return (1);
}

void	set_signal(int n_int, int n_quit)
{

	if (n_int == SH_IGN)
		signal(SIGINT, SIG_IGN);
	if (n_int == SH_DFL)
		signal(SIGINT, SIG_DFL);
	if (n_int == SH_SHELL)
		signal(SIGINT, signal_handler);
	if (n_int == SH_EXIT)
		signal(SIGINT, signal_handler_exit);
	if (n_quit == SH_IGN)
		signal(SIGQUIT, SIG_IGN);
	if (n_quit == SH_DFL)
		signal(SIGQUIT, SIG_DFL);
	if (n_quit == SH_SHELL)
		signal(SIGQUIT, signal_handler);
}