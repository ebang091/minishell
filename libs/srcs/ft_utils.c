#include "../../inc/structure.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, int befsize, int aftsize, int is_rec)
{
	char	*ret;
	int		i;

	ret = malloc(aftsize);
	if (ret)
	{
		i = 0;
		while (ptr && i < befsize)
		{
			ret[i] = ((char *)ptr)[i];
			i++;
		}
		while (i < aftsize)
			ret[i++] = 0;
	}
	if (is_rec)
		free(ptr);
	return ((void *)ret);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strncpy(char *dst, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_replace(char *str, int idx, char *insert, int cutlen)
{
	int		insert_len;
	int		str_len;
	char	*ret;

	insert_len = ft_strlen(insert);
	str_len = ft_strlen(str);
	ret = malloc(sizeof(char) * (str_len + insert_len + 1 - cutlen));
	if (ret == 0)
		return (0);
	ft_strncpy(ret, str, idx);
	ft_strncpy(&ret[idx], insert, insert_len);
	ft_strncpy(&ret[idx + insert_len],
		&str[idx + cutlen], str_len - idx - cutlen);
	return (ret);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
