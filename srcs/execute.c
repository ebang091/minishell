#include "../inc/minish.h"

static int	ft_strcmp_igcase(char *s1, char *s2)
{
	int		i;
	char	c;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i])
	{
		c = s1[i];
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			c = s1[i] - 'A' + 'a';
		if (c != s2[i])
			return (c - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
static char	*find_path(char *cmd, t_stat *stat)
{
	char	**split_path;
	int		i;
	char	*path;
	char 	*pathapp;

	split_path = ft_split(ft_getenv("PATH", stat->env), ':');
	if (split_path == 0)
		return (0);
	i = 0;
#ifdef TEST
	printf("PATH TEST ============\n");
#endif
	while (split_path[i])
	{
		//path = ft_strtjoin(split_path[i], "/", cmd);	//	TODO : 만들지 말지 고민중
		path = ft_strjoin(split_path[i], "/");
		pathapp = ft_strjoin(path, cmd);
		free(path);
#ifdef TEST
		printf("test : %s\n", pathapp);
#endif
		if (pathapp == 0)
			return (clean_content(split_path, -1));
		if (open(pathapp, O_EXCL) != -1)
		{
			clean_content(split_path, -1);
			return (pathapp);
		}
		free(pathapp);
		i++;
	}
	clean_content(split_path, -1);
	return (cmd);
}

static int	exec_builtin(t_lst *node, t_stat *stat)
{
	// if (ft_strcmp_igcase(node->cmd, "echo") == 0)
	// 	return (ft_echo(node->argc, node->argv));
	if (ft_strcmp_igcase(node->cmd, "pwd") == 0)
		return (ft_pwd());
	else if (ft_strcmp_igcase(node->cmd, "env") == 0)
		return (ft_env(stat->env));
	// else if (ft_strcmp_igcase(node->cmd, "cd") == 0)
	// 	return (stat->pipe_num == 0
	// 			&& ft_cd(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "export") == 0)
		return (stat->pipe_num == 0
				&& ft_export(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "unset") == 0)
		return (stat->pipe_num == 0
				&& ft_unset(node->argc, node->argv, &stat->env));
	else if (ft_strcmp_igcase(node->cmd, "exit") == 0)
		return (stat->pipe_num == 0
				&& ft_exit(node->argc, node->argv, stat));
	return (-1);
}

static int	execute(t_lst *input, t_stat *stat)
{
	int	ret;

	ret = exec_builtin(input, stat);	//	TODO : BUILTIN 만들기
	// ret = -1;
	if (ret == -1)
		ret = exec_program(input, stat);
	return (ret);
}

int	exec_program(t_lst *node, t_stat *stat)
{
	pid_t	pid;
	int		fork_ret;
	int		i;

	fork_ret = 0;
	pid = fork();
	if (pid == 0)
	{
		i = 0;
		while (node->cmd[i] && node->cmd[i] != '/')
			i++;
		if ((size_t)i == ft_strlen(node->cmd))
			node->cmd = find_path(node->cmd, stat);
#ifdef TEST
		printf("============ TEST END\n");
		printf("path : [%s]\n", node->cmd);
		printf("실행 결과\n");
#endif
		execve(node->cmd, node->argv, stat->env);
		//print_exec_err(i, node->cmd, stat);
		perror(stat->pgname);
		exit(EXEC_ERROR);
	}
	set_signal(SH_IGN, SH_IGN);
	wait(&fork_ret);
	set_signal(SH_SHELL, SH_IGN);
	return (fork_ret >> 8);
}

int	execute_line(t_lst **input, t_stat *stat)
{
	int	bef_fd[2];
	int	pip_fd[2];
	int	fd_err_idx;
	int	i;

	i = 0;
	while (*input && stat->cmd_ret != -1)
	{
		pipe(pip_fd);
		fd_err_idx = redirect(*input, bef_fd, stat);
		if (fd_err_idx == -2)
			return (1);
		if (fd_err_idx != -1)
			perror("OPEN ERROR");
			//print_fdopen_err((*input)->fdv[fd_err_idx].file, stat);
		file_redirect_from(i++, bef_fd, stat);
		out_redirect_to(*input, bef_fd, pip_fd, stat);
		if (fd_err_idx == -1 && (*input)->cmd && ft_strlen((*input)->cmd))
			stat->cmd_ret = execute(*input, stat);
		rm_heredoc_tmpfile(stat);
		dup2(stat->inFd, STDIN_FILENO);
		dup2(stat->outFd, STDOUT_FILENO);
		del_node_front(input, TRUE);
		pipe_redirect_from(*input, pip_fd);
	}
	return (0);
}