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

void	ft_fill_stack(char **argv, t_st **a)
{
	int		i;
	int		nbr;
	t_st	*tmp;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i], *a);
		tmp = ft_lstnew(nbr, *a);
		ft_lstadd_back(a, tmp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_st	*a;
	t_st	*b;

	if (argc >= 2)
	{
		a = NULL;
		b = NULL;
		ft_fill_stack(argv, &a);
	}
	return (0);
}
