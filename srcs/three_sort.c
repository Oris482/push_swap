/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:27:21 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 17:21:51 by jaesjeon         ###   ########.fr       */
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
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_rrb(lstinfo)
			&& sort_cba(lstinfo, 1));
}

int	sort_acb(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_ra(lstinfo) && func_sa(lstinfo) && func_rra(lstinfo));
	else if (pos == 1)
		return (func_rb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo));
	else
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
}

int	sort_bac(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_sa(lstinfo));
	else if (pos == 1)
		return (func_pa(lstinfo) && func_sb(lstinfo) && func_pa(lstinfo)
			&& func_sa(lstinfo) && func_pa(lstinfo));
	else
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_rrb(lstinfo)
			&& sort_cab(lstinfo, 1));
}

int	sort_bca(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_ra(lstinfo) && func_sa(lstinfo) && func_rra(lstinfo)
			&& func_sa(lstinfo));
	else if (pos == 1)
		return (func_sb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo));
	else
		return (func_rrb(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo));
}

int	sort_cab(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_sa(lstinfo) && sort_acb(lstinfo, 0));
	else if (pos == 1)
		return (func_pa(lstinfo) && func_sb(lstinfo) && func_pa(lstinfo)
			&& func_pa(lstinfo));
	else
		return (func_rrb(lstinfo) && func_pa(lstinfo) && func_rrb(lstinfo)
			&& func_rrb(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
}

int	sort_cba(t_lstinfo *lstinfo, int pos)
{
	if (pos == 0)
		return (func_sa(lstinfo) && sort_bca(lstinfo, 0));
	else if (pos == 1)
		return (func_pa(lstinfo) && func_pa(lstinfo) && func_pa(lstinfo));
	else
		return (func_rrb(lstinfo) && func_pa(lstinfo) && func_rrb(lstinfo)
			&& func_pa(lstinfo) && func_rrb(lstinfo) && func_pa(lstinfo));
}
