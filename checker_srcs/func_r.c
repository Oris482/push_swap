/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:56:39 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 16:57:13 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	func_ra(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (!lstinfo->a_top || !lstinfo->a_top->next)
		return ;
	tmp = lstinfo->a_top;
	lstinfo->a_top = lstinfo->a_top->next;
	lstinfo->a_top->prev = NULL;
	lstinfo->a_bottom->next = tmp;
	tmp->prev = lstinfo->a_bottom;
	tmp->next = NULL;
	lstinfo->a_bottom = tmp;
}

void	func_rb(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (!lstinfo->b_top || !lstinfo->b_top->next)
		return ;
	tmp = lstinfo->b_top;
	lstinfo->b_top = lstinfo->b_top->next;
	lstinfo->b_top->prev = NULL;
	lstinfo->b_bottom->next = tmp;
	tmp->prev = lstinfo->b_bottom;
	tmp->next = NULL;
	lstinfo->b_bottom = tmp;
}

void	func_rra(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (!lstinfo ->a_top || !lstinfo->a_top->next)
		return ;
	tmp = lstinfo->a_bottom;
	lstinfo->a_bottom = lstinfo->a_bottom->prev;
	lstinfo->a_bottom->next = NULL;
	lstinfo->a_top->prev = tmp;
	tmp->next = lstinfo->a_top;
	tmp->prev = NULL;
	lstinfo->a_top = tmp;
}

void	func_rrb(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (!lstinfo->b_top || !lstinfo->b_top->next)
		return ;
	tmp = lstinfo->b_bottom;
	lstinfo->b_bottom = lstinfo->b_bottom->prev;
	lstinfo->b_bottom->next = NULL;
	lstinfo->b_top->prev = tmp;
	tmp->next = lstinfo->b_top;
	tmp->prev = NULL;
	lstinfo->b_top = tmp;
}
