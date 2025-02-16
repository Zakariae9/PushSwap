#include "push_swap.h"

int is_olny_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-')
		{
			return (0);
		}
			
		i++;
	}
	
	return (1);
}

int    is_operation_wrong(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i +1]))
		{
			return (1);
		}
            
        i++;
    }
    return (0);
}

int	is_num_duplicate(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (str[i])
	{
		j = 0;
		counter = 0;
		while (i >= j)
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				counter++;
			if (counter == 2)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_outside_range(char *str)
{
	long long	num;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == '0' || str[i] == '-')
	{
		i++;
		len--;
	}
	if (len > 10)
	{
		return (1);
	}
		
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
	{
		return (1);
	}
	return (0);
}

int	is_input_correct(char *str)
{
	char	**s_str;
	int		i;

	i = 0;
	s_str = ft_split(str, ' ');
	if (is_num_duplicate(s_str) || is_operation_wrong(str) || !is_olny_numbers(str) || !s_str[0])
	{
		free_(s_str, rows(s_str));
		return (0);
	}
	while (s_str[i])
	{
		if (is_outside_range(s_str[i]))
		{
			free_(s_str, rows(s_str));
			return (0);
		}
		i++;
	}
	free_(s_str, rows(s_str));
	return (1);
}
