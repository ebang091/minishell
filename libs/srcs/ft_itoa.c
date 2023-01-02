#include <stdlib.h>

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len ++;
	while (num && (len++ || 1))
		num /= 10;
	return (len);
}

char	*ft_itoa(int num)
{
	char	*ret;
	int		len;
	int		msb;

	msb = 1;
	if (num < 0)
		msb = -1;
	len = ft_numlen(num);
	ret = malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	if (num < 0)
		ret[0] = '-';
	if (num == 0)
		ret[0] = '0';
	ret[len] = 0;
	while (num)
	{
		ret[--len] = (num % 10) * msb + '0';
		num /= 10;
	}
	return (ret);
}
