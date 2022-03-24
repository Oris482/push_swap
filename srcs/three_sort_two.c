/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:27:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 15:05:11 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
