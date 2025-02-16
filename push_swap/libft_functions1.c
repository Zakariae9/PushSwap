#include "push_swap.h"

long long	ft_atoi(const char *nptr)
{
	long long	num;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		if ((nptr[i] == '-') || (nptr[i] == '+'))
			return (0);
	}
	while (ft_isdigit((nptr[i])))
	{
		num *= (10);
		num += (nptr[i] - 48);
		i++;
	}
	return (num * sign);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	is_there_here(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	int	is_there;

	is_there = is_there_here(s, c);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	if (is_there == -1)
		return (NULL);
	return ((char *)(s + is_there));
}
