#include "../inc/minish.h"

static t_lst	*return_free(t_lst *ret)
{
	free(ret);
	return (0);
}

static t_lst	*new_node(t_lst *ret, int pipe_idx, t_elem *e)
{
	ret = ft_realloc(ret, 0, sizeof(t_lst), FALSE);
	while (ret && ret->fdc * 2 + ret->argc < pipe_idx)
	{
		if (e[ret->fdc * 2 + ret->argc].type != ET_STR)
		{
			ret->fdv = ft_realloc(ret->fdv, sizeof(t_fd) * (ret->fdc + 1),
					sizeof(t_fd) * (ret->fdc + 2), TRUE);
			if (ret->fdv == 0)
				return (return_free(ret));
			free(e[ret->fdc * 2 + ret->argc].data);
			e[ret->fdc * 2 + ret->argc].data = 0;
			ret->fdv[ret->fdc].type = e[ret->fdc * 2 + ret->argc].type;
			ret->fdv[ret->fdc].subtype = e[ret->fdc * 2 + ret->argc].subtype;
			ret->fdv[ret->fdc++].file = e[ret->fdc * 2 + ret->argc + 1].data;
		}
		else
		{
			ret->argv = ft_realloc(ret->argv, sizeof(char *) * (ret->argc + 1),
					sizeof(char *) * (ret->argc + 2), TRUE);
			if (ret->argv == 0)
				return (return_free(ret));
			ret->argv[ret->argc++] = e[(ret->fdc * 2) + ret->argc].data;
		}
	}
	return (ret);
}

int	add_node_back(t_lst **head, t_lst *node)
{
	t_lst	*tmp;

	if (node == 0)
	{
		while (del_node_front(head, FALSE))
			;
		return (0);
	}
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*head = node;
	return (1);
}

int	del_node_front(t_lst **head, int is_deep_copied)
{
	t_lst	*tmp;

	if (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (is_deep_copied == TRUE)
		{
			clean_content(tmp->argv, tmp->argc);
			clean_fdv(tmp->fdv, tmp->fdc);
		}
		else if (is_deep_copied == FALSE)
		{
			free(tmp->argv);
			free(tmp->fdv);
		}
		free(tmp);
		return (1);
	}
	return (0);
}

int	listing(t_elem *elems, int elem_cnt, t_lst **lst)
{
	int		i;
	int		pipe_idx;
	t_lst	*node;

	i = 0;
	while (i < elem_cnt)
	{
		pipe_idx = 0;
		while (i + pipe_idx < elem_cnt && elems[i + pipe_idx].type != ET_PIP)
			pipe_idx++;
		node = new_node(0, pipe_idx, &elems[i]);
		if (node->argv)
			node->cmd = node->argv[0];
		if (add_node_back(lst, node) == 0)
			return (1);
		i += pipe_idx;
		if (elems[i].type == ET_PIP)
		{
			free(elems[i].data);
			elems[i++].data = 0;
		}
	}
	free(elems);
	return (0);
}
