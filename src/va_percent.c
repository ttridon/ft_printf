/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:13:23 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/25 17:01:57 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		va_percent(va_list ap, t_flags *flags)
{
	int	i;
	int	len;

	if (ap)
		;
	flags->buf[0] = '%';
	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (flags->tab[10] && !flags->tab[2])
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (++i < len)
			flags->buf[i] = flags->tab[3] < 1 ? ' ' : '0';
	}
	else if (flags->tab[10])
	{
		while (i <= len)
			flags->buf[i++] = flags->tab[3] < 1 ? ' ' : '0';
	}
}
