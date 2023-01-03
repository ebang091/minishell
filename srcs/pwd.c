/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:33 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/01/03 17:18:38 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"
#include "../inc/minish.h"

//@brief current working directory를 알려주는 함수.
//@param 
t_bool command_pwd(void)
{
    char *path;

    path = getcwd(0,0);
    if(path == 0)
    {
        perror(strerror(errno));  //왜 오류가 뜨는 지 모르겠습니당..
		return (1);
    }
    printf("%s",path);
    free(path);
    return 0;
}