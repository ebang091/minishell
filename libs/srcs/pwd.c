#include "../../inc/minishell.h"

int	ft_pwd(void)
{
	char	*path;

	path = getcwd(0, 0);
	if (path == NULL)
	{
		ft_builtin_error(SHELL_NAME, "pwd", strerror(errno));
		return (1);
	}
	printf("%s\n", path);
	free(path);
	return (0);
}
