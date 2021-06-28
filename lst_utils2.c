/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:32:51 by bkael             #+#    #+#             */
/*   Updated: 2021/06/28 15:33:10 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_st *lst)
{
	if (lst)
	{
		lst->prev = NULL;
		lst->next = NULL;
		free(lst);
	}
}

void	ft_lstclear(t_st **lst)
{
	t_st	*current;
	t_st	*prev;

	if (lst)
	{
		current = *lst;
		while (current)
		{
			prev = current;
			current = current->next;
			ft_lstdelone(prev);
		}
		*lst = NULL;
	}
}
