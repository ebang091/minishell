#include "../inc/minish.h"

int	ft_env(char **env)
{
	if (!env)
		return (-1);
	while (*env)
		printf("%s\n", *env++);
	return (0);
}

int	ft_export(int argc, char **argv, char ***env)
{
	if (argc != 0)
	{
		if (ft_setenv(argv[1], env))
			return (-1);
		return (0);
	}
	return (-1);
}

int	ft_unset(int argc, char **argv, char ***env)
{
	if (argc != 0)
	{
		if (ft_rmenv(argv[1], env))
			return (-1);
		return (0);
	}
	return (-1);
}

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (!path)
		return (-1);
	printf("%s\n", path);
	free(path);
	return (0);
}
