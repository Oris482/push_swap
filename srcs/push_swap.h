/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:57 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/03/18 22:14:52 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# define LLONG_MAX 9223372036854775807LL
# define INT_MAX 2147483647LL
# define INT_MIN -2147483648LL

typedef struct s_stack
{
	long long		value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_lstinfo
{
	struct s_stack		*a_top;
	struct s_stack		*a_bottom;
	struct s_stack		*b_top;
	struct s_stack		*b_bottom;
	size_t				arg_cnt;
	struct s_commands	*lst_command;
}	t_lstinfo;

typedef struct s_commands
{
	char				command[4];
	struct s_commands	*next;
}	t_commands;

t_stack	*parse_num_list(int argc, char **argv);
int		print_error(void);
t_stack	*lst_fclean(t_stack *head);
int		func_sa(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_sb(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_pa(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_pb(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_ra(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_rb(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_rra(t_lstinfo *lstinfo, t_commands **lst_command);
int		func_rrb(t_lstinfo *lstinfo, t_commands **lst_command);
int		record_command(t_commands **lst_command, char *command);

#endif
