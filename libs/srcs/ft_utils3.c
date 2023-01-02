#include "../include/util.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	ret;

	dstlen = ft_strlen(dst);
	i = 0;
	if (dstlen + 1 < dstsize)
	{
		while (src[i] && (i + dstlen + 1) < dstsize)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
		dst[dstlen + i] = 0;
	}
	ret = ft_strlen(src);
	if (dstsize != 0)
	{
		if (dstsize <= dstlen)
			ret += dstsize;
		else
			ret += dstlen;
	}
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	size;
	size_t	idx;

	size = ft_strlen(s1);
	idx = 0;
	if (!s1)
		return ((void *)0);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return ((void *)0);
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	idx;
	int		ss;

	idx = 0;
	if (!s1 || !s2)
		return ((void *)0);
	ss = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (1 + ss + ft_strlen(s2)));
	if (!s3)
		return ((void *)0);
	while (s1[idx])
	{
		s3[idx] = s1[idx];
		idx++;
	}
	while (*s2)
		s3[idx++] = *s2++;
	s3[idx] = 0;
	return (s3);
}

char	*ft_strtjoin(char const *s1, char const *s2, char const *s3)
{
	char	*s4;
	size_t	idx;

	idx = 0;
	if (!s1 || !s2 || !s3)
		return ((void *)0);
	s4 = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1) + ft_strlen(s2)
				+ ft_strlen(s3)));
	if (!s4)
		return ((void *)0);
	idx = 0;
	while (*s1)
		s4[idx++] = *s1++;
	while (*s2)
		s4[idx++] = *s2++;
	while (*s3)
		s4[idx++] = *s3++;
	s4[idx] = 0;
	return (s4);
}

int	ft_atoi(const char *str)
{
	int			flag;
	long long	ret;

	flag = 1;
	ret = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (ret * 10 + *str - '0' > 2147483647 && flag == 1)
			return (-1);
		else if (ret * 10 + *str - '0' > 2147483648 && flag == -1)
			return (0);
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return ((int)(ret * flag));
}
