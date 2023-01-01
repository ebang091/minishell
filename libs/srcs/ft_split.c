#include <stdlib.h>

static int	ft_issep(char c1, char c2)
{
	if (c1 == c2 || c1 == '\0')
		return (1);
	return (0);
}

static void	ft_catcat(char *dst, char *src, char c)
{
	size_t		idx;

	idx = 0;
	while (!ft_issep(src[idx], c) && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
}

static size_t	ft_cntsep(char *s, char c)
{
	size_t		cnt;
	size_t		idx;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (!ft_issep(s[idx], c) && ft_issep(s[idx + 1], c))
			cnt++;
		idx++;
	}
	return (cnt);
}

static void	ft_sep(char **ret, char *s, char c)
{
	size_t		size;
	size_t		curr;

	curr = 0;
	while (*s)
	{
		if (ft_issep(*s, c))
			s++;
		else
		{
			size = 0;
			while (!ft_issep(s[size], c) && s[size])
				size++;
			ret[curr] = (char *)malloc(sizeof(char) * size + 1);
			if (!ret[curr])
			{
				while (curr >= 0)
					free(ret[curr--]);
				return ;
			}
			ft_catcat(ret[curr++], s, c);
			s += size;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		size;

	if (!s)
		return ((void *)0);
	size = ft_cntsep((char *)s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	ft_sep(split, (char *)s, c);
	split[size] = 0;
	return (split);
}
