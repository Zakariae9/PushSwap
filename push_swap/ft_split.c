#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static char	**free2d(char **s, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	count_chars(const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start] && s[start] == c)
		start++;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	return (i);
}

static int	position(const char *s, int pos, char c)
{
	while (s[pos] && s[pos] == c)
		pos++;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < words)
	{
		pos = position(s, pos, c);
		str[i] = malloc((count_chars(s, pos, c) + 1));
		if (!str[i])
			return (free2d(str, i));
		ft_strlcpy(str[i], &s[pos], count_chars(s, pos, c) + 1);
		pos += count_chars(s, pos, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
