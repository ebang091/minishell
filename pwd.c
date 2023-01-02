/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjungbang <eunjungbang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 06:36:32 by eunjungbang       #+#    #+#             */
/*   Updated: 2023/01/03 07:59:56 by eunjungbang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minish.h"

//@brief current working directory를 알려주는 함수.
//@param 
bool command_pwd()
{
    char str[1000];
    getcwd(str, 1000)
    printf("%s",str);//1000byte가 적당한가?
}