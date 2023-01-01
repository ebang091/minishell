#include "../../inc/minish.h"

static int	ft_special_cd(int argc, char **argv, char **env)
{
	char	*path;
	char	*msg;
	int		ret;

	path = 0;
	ret = -1;
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "--") == 0))
	{
		path = ft_getenv("HOME", env);
		msg = "HOME not set";
		ret = 0;
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		path = ft_getenv("OLDPWD", env);
		msg = "OLDPWD not set";
		ret = 0;
	}
	if (ret == 0 && path == 0)
		return (ft_builtin_error(SHELL_NAME, "cd", msg));
	else if (ret == 0 && path && chdir(path) == -1)
		return (ft_builtin_error4(SHELL_NAME, "cd", path, strerror(errno)));
	if (ret == 0 && ft_strcmp(msg, "OLDPWD not set") == 0)
		printf("%s\n", path);
	return (ret);
}

int	ft_set_pwd(char ***env)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_getenv("PWD", *env);
	if (pwd == 0)
		pwd = "";
	oldpwd = ft_strjoin("OLDPWD=", pwd);
	if (oldpwd == 0)
		return (1);
	ft_setenv(oldpwd, env);
	free(oldpwd);
	oldpwd = getcwd(0, 0);
	if (oldpwd == 0)
		return (ft_builtin_error(SHELL_NAME, "cd", strerror(errno)));
	pwd = ft_strjoin("PWD=", oldpwd);
	free(oldpwd);
	if (pwd == 0)
		return (1);
	ft_setenv(pwd, env);
	free(pwd);
	return (0);
}

int	ft_cd(int argc, char **argv, char ***env)
{
	char	*path;
	int		ret;

	ret = ft_special_cd(argc, argv, *env);
	if (ret == -1)
	{
		path = argv[1];
		if (ft_strcmp(path, "--") == 0)
			path = argv[2];
		if (chdir(path) == -1)
			return (ft_builtin_error4(SHELL_NAME, "cd", path, strerror(errno)));
		ret = 0;
	}
	if (ret == 0)
		ret = ft_set_pwd(env);
	return (ret);
}
