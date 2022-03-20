/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:51:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 17:30:08 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_to_a(t_lstinfo *lstinfo, int pos, int qty)
{
	if (pos == 1)
		while (qty-- > 0)
		{
			if (!func_pa(lstinfo))
				return (0);
		}
	else
	{
		while (qty-- > 0)
		{
			if (!func_rrb(lstinfo))
				return (0);
			if (!func_pa(lstinfo))
				return (0);
		}
	}
	return (1);
}

static int check_pos_zero(t_stack *cur_stack, int qty)
{
	while (--qty > 0)
	{
		if (cur_stack->value > cur_stack->next->value)
			return (0);
		cur_stack = cur_stack->next;
	}
	return (1);
}

static int check_pos_one(t_stack *cur_stack, int qty)
{
	while (--qty > 0)
	{
		if (cur_stack->value < cur_stack->next->value)
			return (0);
		cur_stack = cur_stack->next;
	}
	return (1);
}

static int check_pos_two(t_stack *cur_stack, int qty)
{
	while (--qty > 0)
	{
		if (cur_stack->value < cur_stack->prev->value)
			return (0);
		cur_stack = cur_stack->prev;
	}
	return (1);
}

int	check_sorted(t_lstinfo *lstinfo, int pos, int qty)
{
	if (pos == 0 && check_pos_zero(lstinfo->a_top, qty))
		return (1);
	else if (pos == 1 && check_pos_one(lstinfo->b_top, qty))
		return (move_to_a(lstinfo, pos, qty));
	else if (check_pos_two(lstinfo->b_bottom, qty))
		return (move_to_a(lstinfo, pos, qty));
	return (0);
}
