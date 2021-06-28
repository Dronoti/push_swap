/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:06:11 by bkael             #+#    #+#             */
/*   Updated: 2021/06/27 13:11:41 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_num
{
	int				n;
	struct s_num	*prev;
	struct s_num	*next;
}				t_st;

void	ft_fill_stack(char **argv, t_st **a);
int		ft_atoi(const char *ptr, t_st *a);
int		ft_isspace(int c);
int		ft_isdigit(int ch, t_st *a);
void	ft_exit(t_st *a);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
t_st	*ft_lstnew(int nbr, t_st *a);
t_st	*ft_lstlast(t_st *lst);
void	ft_lstadd_back(t_st **lst, t_st *new);
void	ft_lstdelone(t_st *lst);
void	ft_lstclear(t_st **lst);
int		ft_lstsize(t_st *lst);
void	ft_lstadd_front(t_st **lst, t_st *new);

#endif