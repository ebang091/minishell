#include "../inc/minish.h"

static int	get_space_idx(const char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

static int	is_special(const char *str, t_elem *elem, t_stat *stat)
{
	int	ret;

	ret = 0;
	elem->type = ET_STR;
	if (*str == '<' || *str == '>' || *str == '|')
		ret = 1;
	if (*str == '<')
	{
		if (*(str + 1) == '<')
			ret = 2;
		elem->type = ET_LTS;
	}
	if (*str == '>')
	{
		if (*(str + 1) == '>')
			ret = 2;
		elem->type = ET_GTS;
	}
	if (*str == '|')
	{
		stat->pipe_num++;
		elem->type = ET_PIP;
	}
	return elem->subtype = ret;	//	갯수
}

static int	get_elem(const char *str, t_elem *elem, t_stat *stat)
{
	int	len;

	len = is_special(str, elem, stat);
	if (len == 0)
	{
		while (str[len] && get_space_idx(&str[len]) == 0
			   && str[len] != '<' && str[len] != '>' && str[len] != '|')
		{
			if (str[len] == '\'' || str[len] == '\"')
				len += ft_quotelen(&str[len]);
			if (str[len])
				len++;
		}
	}
	elem->data = (char *)malloc(sizeof(char) * (len + 1));
	if (!elem->data)
		return (-1);
	ft_strlcpy(elem->data, str, len + 1);
	return (len);
}

t_elem	*tokenizing(const char *str, int *cnt, t_stat *stat)
{
	t_elem	*ret;
	t_elem	*bef;
	int		len;

	*cnt = 0;
	bef = 0;
	while (*str)
	{
		ret = (t_elem *)ft_realloc(bef,
			sizeof(t_elem) * (*cnt + 1), sizeof(t_elem) * (*cnt + 2), FALSE);

		if (ret == 0)
			return (clean_elem(bef, *cnt));
		str += get_space_idx(str);
		len = get_elem(str, &ret[*cnt], stat);
		if (len == -1)
			return (clean_elem(ret, *cnt));
		str += len;
		free(bef);
		bef = ret;
		str += get_space_idx(str);
		(*cnt)++;
	}
	return (ret);
}

t_lst	*input_listing(char *input, t_stat *stat)
{
	t_elem	*elems;
	int		elem_cnt;
	t_lst	*lst;

	lst = 0;
	elems = tokenizing(input, &elem_cnt, stat);
	if (elems == 0
		|| parsing_error(elems, stat)
		|| quote_pairing(elems)
		/*	TODO LEXER
		|| env_transform(elems, stat)
		*/
		|| listing(elems, elem_cnt, &lst))
	{
		if (stat->error >= 0)
			perror(strerror(errno));
			//perror(strerror(errno));
			//print_parse_err(elems, stat);
		else
			stat->error = PARSE_ERROR;
		clean_elem(elems, elem_cnt);
		return (0);
	}
	return (lst);
}