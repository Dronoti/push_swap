/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:21:58 by bkael             #+#    #+#             */
/*   Updated: 2021/07/01 18:22:21 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_st **a, int stack)
{
	int	one;
	int	two;

	one = (*a)->n;
	two = (*a)->next->n;
	if ((one > two && stack == 'a') || (one < two && stack == 'b'))
		ft_swap(a, 1, stack);
}

void	ft_sort_three(t_st **a, int stack)
{
	int	one;
	int	two;
	int	tree;

	one = (*a)->n;
	two = (*a)->next->n;
	tree = (*a)->next->next->n;
	if (one > two && two < tree && one < tree)
		ft_swap(a, 1, stack);
	else if (one > two && two > tree && one > tree)
		ft_swap(a, 1, stack);
	else if (one < two && two > tree && one < tree)
		ft_swap(a, 1, stack);
	one = (*a)->n;
	two = (*a)->next->n;
	tree = (*a)->next->next->n;
	if (one > two && two < tree && one > tree)
		ft_rotate(a, 1, stack);
	else if (one < two && two > tree && one > tree)
		ft_rev_rotate(a, 1, stack);
}

void	ft_sort_five(t_st **a, t_st **b, int len, int *arr)
{
	int	main_len;

	main_len = len;
	while (len > 3)
	{
		if ((*a)->n == arr[0] || ((*a)->n == arr[1] && main_len == 5))
		{
			ft_push(a, b, 'b');
			len--;
		}
		else
			ft_rotate(a, 1, 'a');
	}
	ft_sort_three(a, 'a');
	if (main_len == 5)
		ft_sort_two(b, 'b');
	while (*b)
		ft_push(a, b, 'a');
}

void	ft_find(t_st **a, t_st **b, int *arr, t_parm *parm)
{
	int	steps_up;
	int	steps_down;

	steps_up = ft_steps(a, arr, parm, 0);
	steps_down = ft_steps(a, arr, parm, 1);
	if (steps_up <= steps_down)
	{
		while (steps_up--)
			ft_rotate(a, 1, 'a');
	}
	else
	{
		while (steps_down--)
			ft_rev_rotate(a, 1, 'a');
	}
	ft_push(a, b, 'b');
}

void	ft_big_sort(t_st **a, t_st **b, int len, int *arr)
{
	t_parm	parm;

	parm.block = 1;
	parm.len = len;
	if (len < 25)
		parm.range = 1;
	else if (len <= 100)
		parm.range = 18;
	else if (len > 100 && len < 500)
		parm.range = len / 4;
	else if (len >= 500)
		parm.range = len / 8;
	while (*a)
	{
		while (ft_lstsize(*b) < parm.block * parm.range && *a)
			ft_find(a, b, arr, &parm);
		parm.block++;
	}
	while (parm.len--)
	{
		while ((*b)->n != arr[parm.len])
			ft_direction(b, arr[parm.len], 'b');
		ft_push(a, b, 'a');
	}
}
