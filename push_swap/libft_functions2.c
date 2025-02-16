#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i] == '0' || s1[i] == '+')
		i++;
	while (s2[j] == '0' || s2[j] == '+')
		j++;
	while (((unsigned char)s1[i] || (unsigned char)s2[j]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	l;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size > src_len)
		l = src_len;
	else
		l = size - 1;
	while (i < l)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		s++;
	}
	return (counter);
}
