/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:30:27 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 13:24:42 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char **s)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	while (**s && **s >= '0' && **s <= '9')
	{
		nb = nb * 10 + (**s - 48);
		(*s)++;
	}
	(*s)--;
	return (sign * nb);
}