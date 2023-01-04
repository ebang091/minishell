#include "../inc/minish.h"

void	set_struct(struct sigaction *act, void (*f)(int))
{
	act->__sigaction_u.__sa_handler = f;
}
