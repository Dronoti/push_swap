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
