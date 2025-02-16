#include "push_swap.h"

int	rows(char **s)
{
	int	i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_(char **str, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_num_duplicate1(char **str)
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

int	is_input_correct1(char **str, int words_num)
{
	int	i;

	i = 1;
	if (!is_num_duplicate1(str))
	{
		while (i <= words_num)
		{ 
			if (is_input_correct(str[i]))
				i++;
			else
			{
				return (0);
			}
		}
		return (1);
	}
	return (0);
}

int	is_list_ordered(st_stack *head)
{
	int	small_num;

	small_num = INT_MIN;
	while (head != NULL)
	{
		if (small_num > head->data)
			return (0);
		small_num = head->data;
		head = head->next;
	}
	return (1);
}
