/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/24 17:35:55 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdlib.h>
# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	long long		value;
	int				idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lstinfo
{
	struct s_stack		*a_top;
	struct s_stack		*a_bottom;
	struct s_stack		*b_top;
	struct s_stack		*b_bottom;
	int					a_arg_cnt;
	int					b_arg_cnt;
}	t_lstinfo;

typedef struct s_command
{
	char				command[4];
	struct s_command	*prev;
	struct s_command	*next;
}	t_command;

t_stack		*parse_num_list(int argc, char **argv);
int			print_result(int c);
t_lstinfo	*lst_fclean(t_lstinfo *lstinfo);
int			check_sorted(t_lstinfo *lstinfo);
t_stack		*set_cur_node(t_lstinfo *lstinfo, int pos);
void		do_command(t_lstinfo *lstinfo);

void		func_sa(t_lstinfo *lstinfo);
void		func_sb(t_lstinfo *lstinfo);
void		func_pa(t_lstinfo *lstinfo);
void		func_pb(t_lstinfo *lstinfo);
void		func_ra(t_lstinfo *lstinfo);
void		func_rb(t_lstinfo *lstinfo);
void		func_rra(t_lstinfo *lstinfo);
void		func_rrb(t_lstinfo *lstinfo);

#endif
