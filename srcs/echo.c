#include "../inc/minish.h"

//@brief  stdout 으로 지정된 fd로 command 인자를 출력
//TODO : @성공 시, 실패시 반환 값
//궁금한 점: pipe, redirection 의 경우, stdout을 미리 변경한 후에 실행하면 되나?


int ft_find_option(char *argv)
{
	int	i;
	int cnt;

	i = 1;
	cnt = 0;
	if(argv[0] != '-')
		return (0);
	while (argv[i] && argv[i] == 'n')
	{
			cnt++;
			i++;
	}
	if(argv[i])
		return 0;
	return (cnt);
}

int ft_echo(int argc, char **argv)
{
	int	i;
	int	flag;
	int start;

	i = 1;
	flag = 0;
	start = 1;
	while(i < argc)
	{
		if(ft_find_option(argv[i]))
		{
			if(start)
				flag = 1;					
			else{
				printf("%s", argv[i]);
			}
		}
		else
		{
			printf("%s", argv[i]);
			if (i < argc -1)
				printf(" ");
			start = 0;
		}
		i++;
	}
	if(!flag)
		printf("\n");
	return (0);
}