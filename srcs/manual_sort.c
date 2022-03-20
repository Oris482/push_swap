/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:39:46 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/20 19:45:11 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	manual_sort(t_lstinfo *lstinfo, int pos, int qty)
{
	if (qty == 1)
		return (1);
	else if (qty == 2)
		return (two_sort(lstinfo, pos));
	else if (qty == 3)
		return (three_sort(lstinfo, pos));
	else if (qty == 4)
		return (four_sort(lstinfo, pos));
	else if (qty == 5)
		return (five_sort(lstinfo, pos));
	else
		return (six_sort(lstinfo, pos));
}
