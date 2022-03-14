/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:12 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/14 22:41:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	strtoi(char **str)
{
	int			sign;
	int			digit;
	long long	ret;

	sign = 1;
	digit = 0;
	ret = 0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		if (digit > 10)
			break ;
		ret = ret * 10 + (**str - '0');
		(*str)++;
		digit++;
		if (**str == '\0' || **str == ' ')
			return (ret * sign);
	}
	return (INT_MAX + 1);
}

static t_stack	*ft_makelst(t_stack prev_node, long long value)
{
	t_stack	*node;

	if (value > INT_MAX || value < INT_MIN)
		return (NULL);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = (int)value;
	node->next = NULL;
	if (prev_node != NULL)
	{
		prev_node->next = node;
		node->prev = prev_node;
	}
	else
		node->prev = NULL;
	return (node);
}

static t_stack	**

t_stack	*parse_num_list(int argc, char **argv)
{
	int			idx;
	t_stack		*cur_node;
	t_stack		*prev_node;
	char		*cur;

	idx = 1;
	prev_node = NULL;
	while (idx < argc)
	{
		cur = argv[idx++];
		while (*cur)
		{
			if (ft_isdigit(*cur) || *cur == '+' || *cur == '-')
			{
				cur_node = ft_makelst(prev_node, strtoi(&cur));
				prev_node = cur_node;
			}
			else
				return (full_lstclean(cur_node));
			if (*cur == ' ')
				cur++;
		}
	}
	while (cur_node->prev != NULL)
		cur_node = cur_node->prev;
	return (cur_node);
}
