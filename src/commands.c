/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:42:44 by bkael             #+#    #+#             */
/*   Updated: 2021/07/05 11:43:11 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_st **a, t_st **b, int stack)
{
	t_st	*tmp;

	if (*b && stack == 'a')
	{
		tmp = *b;
		*b = (*b)->next;
		if (*b)
			(*b)->prev = NULL;
		ft_lstadd_front(a, tmp);
		ft_putstr_fd("pa\n", 1);
	}
	if (*a && stack == 'b')
	{
		tmp = *a;
		*a = (*a)->next;
		if (*a)
			(*a)->prev = NULL;
		ft_lstadd_front(b, tmp);
		ft_putstr_fd("pb\n", 1);
	}
}

void	ft_swap(t_st **a, int visible, int stack)
{
	int	tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->n;
		(*a)->n = (*a)->next->n;
		(*a)->next->n = tmp;
		if (visible && stack == 'a')
			ft_putstr_fd("sa\n", 1);
		if (visible && stack == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_swap_s(t_st **a, t_st **b)
{
	ft_swap(a, 0, 'a');
	ft_swap(b, 0, 'b');
	if ((*b && (*b)->next) || (*a && (*a)->next))
		ft_putstr_fd("ss\n", 1);
}

void	ft_rotate(t_st **a, int visible, int stack)
{
	t_st	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		(*a)->prev = NULL;
		ft_lstadd_back(a, tmp);
		if (visible && stack == 'a')
			ft_putstr_fd("ra\n", 1);
		if (visible && stack == 'b')
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_rotate_r(t_st **a, t_st **b)
{
	ft_rotate(a, 0, 'a');
	ft_rotate(b, 0, 'b');
	if ((*b && (*b)->next) || (*a && (*a)->next))
		ft_putstr_fd("rr\n", 1);
}
