/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:43:18 by bkael             #+#    #+#             */
/*   Updated: 2021/07/05 11:43:39 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_st **a, int visible, int stack)
{
	t_st	*tmp;

	if (*a && (*a)->next)
	{
		tmp = ft_lstlast(*a);
		tmp->prev->next = NULL;
		ft_lstadd_front(a, tmp);
		if (visible && stack == 'a')
			ft_putstr_fd("rra\n", 1);
		if (visible && stack == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rev_rotate_r(t_st **a, t_st **b)
{
	ft_rev_rotate(a, 0, 'a');
	ft_rev_rotate(b, 0, 'b');
	if ((*b && (*b)->next) || (*a && (*a)->next))
		ft_putstr_fd("rrr\n", 1);
}
