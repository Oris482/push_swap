/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:56:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 16:21:47 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	func_sa(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	tmp = lstinfo->a_top->next;
	if (tmp->next)
		tmp->next->prev = lstinfo->a_top;
	lstinfo->a_top->next = tmp->next;
	lstinfo->a_top->prev = tmp;
	tmp->next = lstinfo->a_top;
	tmp->prev = NULL;
	lstinfo->a_top = tmp;
	if (lstinfo->a_top->next->next == NULL)
		lstinfo->a_bottom = lstinfo->a_top->next;
}

void	func_sb(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	tmp = lstinfo->b_top->next;
	if (tmp->next)
		tmp->next->prev = lstinfo->b_top;
	lstinfo->b_top->next = tmp->next;
	lstinfo->b_top->prev = tmp;
	tmp->next = lstinfo->b_top;
	tmp->prev = NULL;
	lstinfo->b_top = tmp;
	if (lstinfo->b_top->next->next == NULL)
		lstinfo->b_bottom = lstinfo->b_top->next;
}

void	func_pa(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (lstinfo->a_top == NULL)
	{
		lstinfo->a_top = lstinfo->b_top;
		lstinfo->b_top = lstinfo->b_top->next;
		lstinfo->b_top->prev = NULL;
		lstinfo->a_top->next = NULL;
		lstinfo->a_bottom = lstinfo->a_top;
	}
	else
	{
		tmp = lstinfo->b_top;
		lstinfo->b_top = tmp->next;
		if (lstinfo->b_top)
			lstinfo->b_top->prev = NULL;
		tmp->next = lstinfo->a_top;
		lstinfo->a_top->prev = tmp;
		lstinfo->a_top = tmp;
	}
	if (lstinfo->b_top == NULL)
		lstinfo->b_bottom = NULL;
	lstinfo->a_arg_cnt++;
	lstinfo->b_arg_cnt--;
}

void	func_pb(t_lstinfo *lstinfo)
{
	t_stack	*tmp;

	if (lstinfo->b_top == NULL)
	{
		lstinfo->b_top = lstinfo->a_top;
		lstinfo->a_top = lstinfo->a_top->next;
		lstinfo->a_top->prev = NULL;
		lstinfo->b_top->next = NULL;
		lstinfo->b_bottom = lstinfo->b_top;
	}
	else
	{
		tmp = lstinfo->a_top;
		lstinfo->a_top = tmp->next;
		if (lstinfo->a_top)
			lstinfo->a_top->prev = NULL;
		tmp->next = lstinfo->b_top;
		lstinfo->b_top->prev = tmp;
		lstinfo->b_top = tmp;
	}
	if (lstinfo->a_top == NULL)
		lstinfo->a_bottom = NULL;
	lstinfo->a_arg_cnt--;
	lstinfo->b_arg_cnt++;
}
