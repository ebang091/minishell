#include "../inc/minish.h"

int	parsing_error(t_elem *elems, t_stat *stat)
{
	int	i;
	int	schar;
	int	last_type;

	i = 0;
	schar = 0;
	if (elems[0].type == ET_PIP)
	{
		stat->error = 0;
		return (1);
	}
	while (elems[i].data && schar < 2)
	{
		last_type = elems[i++].type;
		if (last_type == ET_STR && schar == 1)
			schar = 0;
		if (last_type != ET_STR)
			schar++;
	}
	if (!(schar > 1 || last_type != ET_STR))
		return (0);
	stat->error = i - 1;
	return (1);
}