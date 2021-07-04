/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:04:27 by bkael             #+#    #+#             */
/*   Updated: 2021/06/27 13:14:20 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_onearg_stack(int argc, char **argv, t_st **a)
{
	int		i;
	int		nbr;
	t_st	*tmp;

	i = 0;
	while (argv[1][i])
	{
		while (ft_isspace(argv[1][i]))
			i++;
		if (argv[1][i])
		{
			nbr = ft_atoi(argc, argv[1] + i, *a);
			tmp = ft_lstnew(nbr, *a);
			ft_lstadd_back(a, tmp);
			while (!ft_isspace(argv[1][i]) && argv[1][i])
				i++;
		}
	}
}

void	ft_fill_stack(int argc, char **argv, t_st **a)
{
	int		i;
	int		nbr;
	t_st	*tmp;

	if (argc == 2)
		ft_onearg_stack(argc, argv, a);
	else
	{
		i = 1;
		while (argv[i])
		{
			nbr = ft_atoi(argc, argv[i], *a);
			tmp = ft_lstnew(nbr, *a);
			ft_lstadd_back(a, tmp);
			i++;
		}
	}
}

int	*ft_create_sort_arr(t_st *lst, int len)
{
	t_st	*tmp;
	int		*arr;
	int		i;

	i = 0;
	tmp = lst;
	arr = (int *)malloc(sizeof(int) * len);
	while (tmp)
	{
		arr[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	ft_qsort(arr, 0, len - 1);
	return (arr);
}

void	ft_sort(t_st **a, t_st **b, int *arr)
{
	int	len;

	len = ft_lstsize(*a);
	if (len == 2)
		ft_sort_two(a, 'a');
	else if (len == 3)
		ft_sort_three(a, 'a');
	else if (len == 4 || len == 5)
		ft_sort_five(a, b, len, arr);
	else
		ft_big_sort(a, b, len, arr);
}

int	main(int argc, char **argv)
{
	t_st	*a;
	t_st	*b;
	int		*arr;

	if (argc >= 2)
	{
		a = NULL;
		b = NULL;
		ft_fill_stack(argc, argv, &a);
		if (a)
		{
			ft_lstdupnbr(a);
			if (ft_lstsorted(a))
			{
				ft_lstclear(&a);
				exit(EXIT_SUCCESS);
			}
			arr = ft_create_sort_arr(a, ft_lstsize(a));
			ft_sort(&a, &b, arr);
			ft_lstclear(&a);
			ft_lstclear(&b);
			free(arr);
		}
	}
	return (0);
}
