/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:56:33 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/18 22:14:29 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	func_sa(t_lstinfo *lstinfo, t_commands **lst_command)
{
	t_stack	*temp;

	temp = lstinfo->a_top->next;
	lstinfo->a_top->next = temp->next;
	temp->prev = lstinfo->a_top;
	lstinfo->a_top->prev = temp;
	temp->next = lstinfo->a_top;
	temp->prev = NULL;
	lstinfo->a_top = temp;
	if (lstinfo->a_top->next->next == NULL)
		lstinfo->a_bottom = lstinfo->a_top->next;
	return (record_command(lst_command, "sa"));
}

int	func_sb(t_lstinfo *lstinfo, t_commands **lst_command)
{
	t_stack	*temp;

	temp = lstinfo->b_top->next;
	lstinfo->b_top->next = temp->next;
	temp->prev = lstinfo->b_top;
	lstinfo->b_top->prev = temp;
	temp->next = lstinfo->b_top;
	temp->prev = NULL;
	lstinfo->b_top = temp;
	if (lstinfo->b_top->next->next == NULL)
		lstinfo->b_bottom = lstinfo->b_top->next;
	return (record_command(lst_command, "sb"));
}

int	func_pa(t_lstinfo *lstinfo, t_commands **lst_command)
{
	t_stack	*tmp;

	if (lstinfo->a_top == NULL)
	{
		lstinfo->a_top = lstinfo->b_top;
		lstinfo->b_top = lstinfo->b_top->next;
		lstinfo->b_top->prev = NULL;
		lstinfo->a_top->next = NULL;
		lstinfo->a_top->prev = NULL;
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
	return (record_command(lst_command, "pa"));
}

int	func_pb(t_lstinfo *lstinfo, t_commands **lst_command)
{
	t_stack	*tmp;

	if (lstinfo->b_top == NULL)
	{
		lstinfo->b_top = lstinfo->a_top;
		lstinfo->a_top = lstinfo->a_top->next;
		lstinfo->a_top->prev = NULL;
		lstinfo->b_top->next = NULL;
		lstinfo->b_top->prev = NULL;
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
	return (record_command(lst_command, "pb"));
}
