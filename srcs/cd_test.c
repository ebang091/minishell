#include "../inc/minish.h"
#include "../inc/include.h"

char *find_path(char **argv)
{
	int	i;

	i = -1;
	while (*argv[++i] != 0)
	{
		printf("commands: %s\n", argv[i]);
		if (argv[i][0] == 'c' && argv[i][1] == 'd')	
			break;
	}
	i++;
	printf("in find path:  %s\n", argv[i]);
	return (argv[i]);
}

int ft_set_pwd(char ***env)
{
	char	*path;

	path = ft_getenv("PWD", *env);
	if (!path)
		path = "";
	path = ft_strjoin("OLDPWD=", path);
	if (ft_setenv(path, env))
		return (-1);
	path = getcwd(0, 0);
	if (!path)
		return (ft_builtin_error(SHELL_NAME, "cd", "HOME not set"));
	path = ft_strjoin("PWD=", path);
	if (ft_setenv(path, env))
		return (-1);
	free(path);
	return (0);
}

int cd_go_HOME(char ***env)
{
	//pwd환경변수 불러옴.   <- 오류 가능성: PWD 환경 변수 unset되어있을 때. (나의 오류처리: 오류 출력 - bash 처럼)
	//그 경로로 chdir함. 
	char	*path;

	path = ft_getenv("HOME", *env);
	if (!path)
		{
			ft_builtin_error4("minishell", "cd", "", strerror(errno)); // HOME not set으로 출력?
			return (0);
		}
	if (chdir(path) == -1)
	{
		return (0);
	}
	return(1);	
}

int	ft_cd(int argc, char **argv, char ***env)
{
	int		ret;
	char	 *path;

	printf("cd command execute!\n\n");
	path = find_path(argv);
	printf("parsed path: %s\n", path);
	if(!ft_strcmp(path, "") || !strcmp(path, "--"))
	{
		if (!cd_go_HOME(env))
			return (-1);
	}
	else if (!strcmp(path, "-"))
	{
		printf("cd - 입력함\n");
		if(!cd_go_back(env))
			return (-1);
	}
	else
	{
		if(chdir(path))
			ft_builtin_error("cd", "no such file or directory", path);
	}
	ret = ft_set_pwd(env);
	return (ret);
}