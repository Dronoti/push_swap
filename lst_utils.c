/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:18:06 by bkael             #+#    #+#             */
/*   Updated: 2021/06/28 12:18:27 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st	*ft_lstnew(int nbr, t_st *a)
{
	t_st	*new;

	new = (t_st *)malloc(sizeof(t_st));
	if (!new)
		ft_exit(a);
	new->n = nbr;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_st	*ft_lstlast(t_st *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_st *lst)
{
	int		i;
	t_st	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_st **lst, t_st *new)
{
	t_st	*back;

	if (new && lst)
	{
		new->next = NULL;
		if (!*lst)
		{
			new->prev = NULL;
			*lst = new;
			return ;
		}
		back = ft_lstlast(*lst);
		back->next = new;
		new->prev = back;
	}
}

void	ft_lstadd_front(t_st **lst, t_st *new)
{
	if (lst && new)
	{
		new->next = *lst;
		new->prev = NULL;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}
