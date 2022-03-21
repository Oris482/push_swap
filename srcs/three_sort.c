/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:27:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/21 21:22:37 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_abc(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (1);
	else if (pos == 1)
		return (func_rb(lstinfo) && func_sb(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_abc(lstinfo, 1));
		return (func_rrb(lstinfo) && func_pa(lstinfo) && func_rrb(lstinfo)
			&& func_pa(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo));
	}
}

int	sort_acb(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
	{
		if (lstinfo->a_top->next->next->next == NULL)
			return (func_sa(lstinfo) && func_ra(lstinfo));
		else
			return (func_ra(lstinfo) && func_sa(lstinfo) && func_rra(lstinfo));
	}
	else if (pos == 1)
		return (func_rb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_acb(lstinfo, 1));
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo));
	}
}

int	sort_bac(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_sa(lstinfo));
	else if (pos == 1)
		return (func_pa(lstinfo) && func_sb(lstinfo) && func_pa(lstinfo)
			&& func_sa(lstinfo) && func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_bac(lstinfo, 1));
		return (func_rrb(lstinfo) && func_pa(lstinfo) && func_rrb(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
	}
}

int	sort_bca(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
	{
		if (lstinfo->a_top->next->next->next == NULL)
			return (func_rra(lstinfo));
		else
			return (func_ra(lstinfo) && func_sa(lstinfo) && func_rra(lstinfo)
				&& func_sa(lstinfo));
	}
	else if (pos == 1)
		return (func_sb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_bca(lstinfo, 1));
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
	}
}

int	sort_cab(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
	{
		if (lstinfo->a_top->next->next->next == NULL)
			return (func_ra(lstinfo));
		else
			return (func_sa(lstinfo) && sort_acb(lstinfo, 0));
	}
	else if (pos == 1)
		return (func_pa(lstinfo) && func_sb(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_cab(lstinfo, 1));
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_rrb(lstinfo)
			&& sort_cab(lstinfo, 1));
	}
}

int	sort_cba(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_sa(lstinfo) && sort_bca(lstinfo, 0));
	else if (pos == 1)
		return (func_pa(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
	else
	{
		if (lstinfo->b_bottom->prev->prev == lstinfo->b_top)
			return (sort_cba(lstinfo, 1));
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_rrb(lstinfo)
			&& sort_cba(lstinfo, 1));
	}
}

int	three_sort(t_lstinfo *lstinfo, int pos)
{
	t_stack	*cur_node;
	int		arr[3];

	cur_node = set_cur_node(lstinfo, pos);
	if (pos == 2)
		cur_node = cur_node->prev->prev;
	arr[0] = cur_node->idx;
	arr[1] = cur_node->next->idx;
	arr[2] = cur_node->next->next->idx;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return (sort_abc(lstinfo, pos));
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] < arr[2])
		return (sort_acb(lstinfo, pos));
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] < arr[2])
		return (sort_bac(lstinfo, pos));
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[0] > arr[2])
		return (sort_bca(lstinfo, pos));
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[0] > arr[2])
		return (sort_cab(lstinfo, pos));
	else if (arr[0] > arr[1] && arr[1])
		return (sort_cba(lstinfo, pos));
	return (0);
}
