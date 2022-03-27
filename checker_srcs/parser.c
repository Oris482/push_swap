/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:45:12 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/27 17:46:12 by jaesjeon         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*lst_stack_clean(t_stack *head)
{
	t_stack	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free (tmp);
	}
	return (NULL);
}

static t_stack	*ft_makelst(t_stack *prev_node, long long value)
{
	t_stack	*node;

	if (value > INT_MAX || value < INT_MIN)
		return (NULL);
	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->idx = 0;
	if (prev_node != NULL)
	{
		prev_node->next = node;
		node->prev = prev_node;
	}
	else
		node->prev = NULL;
	return (node);
}

static void	set_nextnode(t_stack **cur, int *sign, int *digit, char **str)
{
	t_stack	*prev;

	while (**str && **str == ' ')
		(*str)++;
	(*cur)->value *= (long long)*sign;
	prev = *cur;
	if (**str)
		*cur = ft_makelst(prev, 0);
	*sign = 0;
	*digit = 0;
}

static t_stack	*put_strtoi(t_stack **cur_node, char *str)
{
	int			sign;
	int			digit;

	sign = 0;
	digit = 0;
	while (*str != '\0' && *str != ' ')
	{
		if (sign == 0 && (*str == '+' || *str == '-'))
		{
			if (*str == '-')
				sign = -1;
			str++;
		}
		if (!sign)
			sign = 1;
		if (digit > 9 || !ft_isdigit(*str))
			return (NULL);
		(*cur_node)->value = (*cur_node)->value * 10 + (*str++ - '0');
		digit++;
		if (*str != '\0' && *str == ' ')
			set_nextnode(cur_node, &sign, &digit, &str);
		else if (*str == '\0' || *str == ' ')
			(*cur_node)->value *= (long long)sign;
	}
	return (*cur_node);
}

t_stack	*parse_num_list(int argc, char **argv)
{
	int			idx;
	t_stack		*cur_node;
	t_stack		*head;
	char		*cur_arg;

	idx = 1;
	head = NULL;
	cur_node = head;
	while (idx < argc)
	{
		cur_node = ft_makelst(cur_node, 0);
		if (cur_node == NULL)
			return (lst_stack_clean(head));
		if (head == NULL)
			head = cur_node;
		cur_arg = argv[idx++];
		while (*cur_arg == ' ')
			cur_arg++;
		if (*cur_arg == '\0')
			return (lst_stack_clean(head));
		cur_node = put_strtoi(&cur_node, cur_arg);
		if (cur_node == NULL)
			return (lst_stack_clean(head));
	}
	return (head);
}
