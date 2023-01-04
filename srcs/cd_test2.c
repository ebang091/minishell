#include "../inc/minish.h"
#include "../inc/include.h"

int cd_go_back(char ***env)
{
	//oldpwd환경변수 불러옴.   <- 오류 가능성: PWD 환경 변수 unset되어있을 때. (나의 오류처리: 오류 출력 - bash 처럼)
	//그 경로로 chdir함. 

	char	*path;

	path = ft_getenv("OLDPWD", *env);
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