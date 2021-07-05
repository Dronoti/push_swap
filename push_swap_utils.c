/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkael <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:05:40 by bkael             #+#    #+#             */
/*   Updated: 2021/07/05 12:06:51 by bkael            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(int argc, int ch, t_st *a)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else if (argc == 2 && ch == ' ')
		return (0);
	else if (ch != '\0')
		ft_exit(a);
	return (0);
}

int	ft_atoi(int argc, const char *ptr, t_st *a)
{
	unsigned int	i;
	long long		num;
	long long		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(ptr[i]))
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(argc, ptr[i], a))
	{
		num = num * 10 + (ptr[i] - '0');
		if (num > 2147483647 && sign == 1)
			ft_exit(a);
		if (num > 2147483648 && sign == -1)
			ft_exit(a);
		i++;
	}
	return (num * sign);
}
