#include "../inc/minish.h"

static int	heredoc_eof(char *input, int input_len, char *end, int end_len)
{
	int	i;

	if (input && input_len > end_len)
	{
		i = 0;
		while (i < end_len && input[input_len - 1 - end_len + i] == end[i])
			i++;
		if (i == end_len)
		{
			if (input_len > end_len + 1)
				if (input[input_len - 1 - end_len - 1] != '\n')
					return (0);
			input[input_len - 1 - end_len] = 0;
			return (1);
		}
	}
	return (0);
}

char	*heredoc_input(char *eof, t_stat *stat)
{
	char	*input;
	int		len;
	int		total_len;

	total_len = 0;
	input = 0;
	len = 1;
	while (len != 0
		&& !heredoc_eof(input, total_len, eof, ft_strlen(eof)))
	{
		if (total_len == 0 || (total_len && input[total_len - 1] == '\n'))
			write(1, "> ", 2);
		input = ft_realloc(input, total_len, total_len + HEREDOC_RDBYTE + 1, 1);
		if (input == 0)
			return (0);
		len = read(stat->out_fd, &input[total_len], HEREDOC_RDBYTE);
		total_len += len;
	}
	return (input);
}

void	rm_heredoc_tmpfile(t_stat *stat)
{
	if (stat->exist_tmp)
	{
		unlink(HEREDOC_TMPFILE);
		stat->exist_tmp = 0;
	}
}

int	heredoc(t_fd *fd, t_stat *stat)
{
	char	*input;
	int		fd_in;
	pid_t	pid;

	set_signal(SH_EXIT, SH_IGN);
	pid = fork();
	if (pid == 0)
	{
		input = heredoc_input(fd->file, stat);
		if (input == 0)
			exit(2);
		input = env_setting(input, 1, stat);
		if (input == 0)
			exit(2);
		fd_in = open(HEREDOC_TMPFILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
		if (fd_in != -1)
			write(fd_in, input, ft_strlen(input));
		free(input);
		close(fd_in);
		exit(0);
	}
	set_signal(SH_IGN, SH_IGN);
	wait(&fd_in);
	set_signal(SH_SHELL, SH_IGN);
	return (fd_in >> 8);
}
