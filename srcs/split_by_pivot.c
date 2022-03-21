
#include "push_swap.h"

static int  split_pos_zero(t_lstinfo *lstinfo, int s_pivot, int b_pivot, int qty)
{
    int rewind;
    int error;

	rewind = 0;
	while (qty-- > 0)
	{
		if (lstinfo->a_top->idx >= b_pivot)
		{
			rewind++;
			error = func_ra(lstinfo);
		}
		else if (lstinfo->a_top->idx >= s_pivot)
			error = func_pb(lstinfo);
		else
		{
			if (!func_pb(lstinfo))
				return (0);
			error = func_rb(lstinfo);
		}
		if (error == 0)
			return (0);
	}
	if (!rewind_stack(lstinfo, 0, rewind))
		return (0);
	return (1);
}

static int  split_pos_one(t_lstinfo *lstinfo, int m_pivot, int qty)
{
	while (qty-- > 0)
	{
		if (lstinfo->b_top->idx >= m_pivot)
        {
            if (!func_pa(lstinfo))
                return (0);
        }
		else
        {
			if (!func_rb(lstinfo))
                return (0);
        }
	}
	return (1);
}

static int  split_pos_two(t_lstinfo *lstinfo, int m_pivot, int qty)
{
	while (qty-- > 0)
	{
        if (!func_rrb(lstinfo))
            return (0);
		if (lstinfo->b_top->idx >= m_pivot)
		{
            if (!func_pa(lstinfo))
                return (0);
		}
	}
	return (1);
}

int	split_by_pivot(t_lstinfo *lstinfo, int start, int end, int pos)
{
    int qty;
    int s_pivot;
    int b_pivot;
    int m_pivot;

    qty = end - start + 1;
    s_pivot = start + (qty / 3);
    b_pivot = s_pivot + (qty / 3);
    m_pivot = start + (qty / 2);
    if (pos == 0)
        return (split_pos_zero(lstinfo, s_pivot, b_pivot, qty)
            && three_split(lstinfo, b_pivot, end, 0)
            && three_split(lstinfo, s_pivot, b_pivot - 1, 1)
            && three_split(lstinfo, start, s_pivot - 1, 2));
    if (pos == 1)
        return (split_pos_one(lstinfo, m_pivot, qty)
            && three_split(lstinfo, m_pivot, end, 0)
            && three_split(lstinfo, start, m_pivot - 1, 2));
    if (pos == 2)
        return (split_pos_two(lstinfo, m_pivot, qty)
            && three_split(lstinfo, m_pivot, end, 0)
            && three_split(lstinfo, start, m_pivot - 1, 1));
    return (0);
}