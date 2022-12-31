#include <stdlib.h>
#include "../inc/minish.h"

/**
 * @brief str[idx : idx + dellen] => insert
 * @param str source string
 * @param idx start index
 * @param dellen end index
 * @param insert string to replace
 * @return new string
 */
char	*ft_replace(char *str, int idx, int dellen,char *insert)
{
	int		insert_len;
	int		str_len;
	char	*ret;

	insert_len = ft_strlen(insert);
	str_len = ft_strlen(str);
	ret = (char*)malloc(sizeof(char) * (str_len + insert_len - dellen + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, str, idx + 1);
	ft_strlcpy(&ret[idx], insert, insert_len + 1);
	ft_strlcpy(&ret[idx + insert_len],
			   &str[idx + dellen], str_len - idx - dellen + 1);
	return (ret);
}

/**
 * @param str string started with ' or "
 * @return length of 'str' without quote
 */
int	ft_quotelen(const char *str)
{
	int		len;

	if (*str == '\'' || *str == '\"')
	{
		len = 1;
		while (str[len] && *str != str[len])
			len++;
		return (len);
	}
	return (0);
}

/**
 * @brief copy arr's elem value
 * @param arr like envp
 * @return new arr
 */

char	**deep_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (arr[idx])
	{
		ret[idx] = (char *)malloc(sizeof(char) * (ft_strlen(arr[idx]) + 1));
		if (ret[idx] == 0)
			return (clean_content(ret, idx));
		ft_strlcpy(ret[idx], arr[idx], ft_strlen(arr[idx]) + 1);
		idx++;
	}
	ret[idx] = 0;
	return (ret);
}

/**
 * copy arr's elem pointer
 * @param arr like envp
 * @return new arr
 */
char	**shallow_copy(char **arr)
{
	char	**ret;
	int		idx;

	idx = 0;
	while (arr[idx])
		idx++;
	ret = (char **)malloc(sizeof(char *) * (idx + 1));
	if (!ret)
		return (0);
	idx = -1;
	while (arr[++idx])
		ret[idx] = arr[idx];
	ret[idx] = 0;
	return (ret);
}