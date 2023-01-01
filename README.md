# 깃공부

```sh
Makefile	include		srcs

libs/include:
env.h	libs.h	pwd.h

libs/srcs:
cd.c			exit.c			ft_utils.c		var_handler.c
echo.c			ft_itoa.c		ft_utils2.c
env.c			ft_print_error.c	ft_utils3.c
env_utils.c		ft_split.c		pwd.c
```

이미 만들었던 파일이고 일정 부분은 util같은 곳에서 가져다가 복구✅

일단 cd pwd exit 같은 경우에는 만들어야하니 우선적으로 만들어주십시오 ㅎ

1. What : cd.c echo.c exit.c env.c(print) pwd.c

2. How : 
	a. 여기(Subject) 말고 main branch에서 갈라져나오는 BuiltIn 브랜치를 만듦
	b. srcs/cd.c srcs/echo.c ... ebang스럽게 작성
	c. 변경 사항을 추가해 커밋, 커밋 메시지는 [feat] $(할 말) 쓰시면 됩니다
		- 🌝 남들 어떻게 쓰는지 보려면 "커밋 컨벤션"을 찾아보시오🌝
	d. 로컬 변경 사항을 remote(github.com)에 push
	e. github으로 돌아와 레포지토리에 변경 사항 올라온거 확인 후 PR

3. Then : 제가 들어온 PR 요청 확인 후, 머지
