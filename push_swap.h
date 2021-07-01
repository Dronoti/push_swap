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

void	ft_fill_stack(int argc, char **argv, t_st **a);
void	ft_onearg_stack(int argc, char **argv, t_st **a);
int		ft_atoi(int argc, const char *ptr, t_st *a);
int		ft_isspace(int c);
int		ft_isdigit(int argc, int ch, t_st *a);
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
int		ft_lstsorted(t_st *lst);
void	ft_lstdupnbr(t_st *lst);
int		*ft_create_sort_arr(t_st *lst, int len);
void	ft_qsort(int *arr, int left, int right);
void	ft_push(t_st **a, t_st **b, int stack);
void	ft_swap(t_st **a, int visible, int stack);
void	ft_swap_s(t_st **a, t_st **b);
void	ft_rotate(t_st **a, int visible, int stack);
void	ft_rotate_r(t_st **a, t_st **b);
void	ft_rev_rotate(t_st **a, int visible, int stack);
void	ft_rev_rotate_r(t_st **a, t_st **b);

#endif