#include "../inc/minish.h"

//@brief chdir 함수를 사용해서 원하는 디렉토리로 변경
//getenv는 허용함수인가?? 
//@param . , .. , [디렉토리 명] 구분
//@param .이면 그대로, ..이면 이전 경로, [디렉토리 명]이면 chdir

t_bool command_cd(int argc, char *argv[])
{
	if (argc == 1) {
		chdir(getenv("HOME"));
	} else if (argc == 2) {
		if (chdir(argv[1]))
			printf("No directory\n");
	} else printf("USAGE: cd [dir]\n");

	return 1;
}
