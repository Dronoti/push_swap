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

void	ft_find(t_st **a, t_st **b, int range, int block, int *arr, int len)
{
	int	steps_up;
	int	steps_down;

	steps_up = ft_steps_up(a, block, range, arr, len);
	steps_down = ft_steps_down(a, block, range, arr, len);
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
	int	block;
	int	range;
	int	i;

	block = 1;
	if (len < 25)
		range = 1;
	else if (len < 100)
		range = 20;
	else if (len >= 100 && len < 500)
		range = len / 4;
	else if (len >= 500)
		range = len / 8;
	while (*a)
	{
		while (ft_lstsize(*b) < block * range && *a)
			ft_find(a, b, range, block, arr, len);
		block++;
	}
	i = len - 1;
	while (*b)
	{
		while ((*b)->n != arr[i])
			ft_find_direction(b, arr[i], len, 'b');
		ft_push(a, b, 'a');
		i--;
	}
}
