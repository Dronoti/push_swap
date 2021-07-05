/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:06:13 by bkael             #+#    #+#             */
/*   Updated: 2021/06/28 13:06:39 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_st *a)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		ft_lstclear(&a);
	exit(EXIT_FAILURE);
}

void	ft_qsort(int *arr, int left, int right)
{
	int	pivot;
	int	min;
	int	max;
	int	tmp;

	min = left;
	max = right;
	pivot = arr[(max + min) / 2];
	while (min <= max)
	{
		while (arr[max] > pivot)
			max--;
		while (arr[min] < pivot)
			min++;
		if (min <= max)
		{
			tmp = arr[min];
			arr[min++] = arr[max];
			arr[max--] = tmp;
		}
		if (left < max)
			ft_qsort(arr, left, max);
		if (right > min)
			ft_qsort(arr, min, right);
	}
}

void	ft_direction(t_st **b, int nbr, int stack)
{
	int		index;
	t_st	*tmp;

	tmp = *b;
	index = 0;
	while (tmp && tmp->n != nbr)
	{
		tmp = tmp->next;
		index++;
	}
	if (index > ft_lstsize(*b) / 2)
		ft_rev_rotate(b, 1, stack);
	else
		ft_rotate(b, 1, stack);
}

int	ft_steps(t_st **a, int *arr, t_parm *parm, int direction)
{
	int		steps;
	int		start;
	t_st	*tmp;

	steps = direction;
	if (direction)
		tmp = ft_lstlast(*a);
	else
		tmp = *a;
	while (tmp)
	{
		start = parm->block * parm->range - parm->range;
		while (start < parm->block * parm->range && start < parm->len)
		{
			if (tmp->n == arr[start])
				return (steps);
			start++;
		}
		if (direction)
			tmp = tmp->prev;
		else
			tmp = tmp->next;
		steps++;
	}
	return (-1);
}
