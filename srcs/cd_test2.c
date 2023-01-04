#include "../inc/minish.h"
#include "../inc/include.h"

int cd_go_back(char ***env)
{
	char	*path;

	path = ft_getenv("OLDPWD", *env);
	printf("path : %s\n", path);
	if (!path)
		{
			ft_builtin_error4("minishell", "cd", "", "OLDPWD not set"); 
			return (0);
		}
	if (chdir(path) == -1)
	{
		return (0);
	}
	return(1);
}