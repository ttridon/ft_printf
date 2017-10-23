/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putpointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:23:33 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/09 16:58:12 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	do_precision(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[11] - i + 2;
	if (len > 0)
	{
		while (--i >= 2)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len + 2] = '0';
	}
}

static void	do_minus(t_flags *flags)
{
	int i;

	i = 0;
	while (flags->buf[i])
		i++;
	while (i < flags->tab[10])
	{
		flags->buf[i] = ' ';
		i++;
	}
}

static void	do_length(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (len <= 0)
		return ;
	if (flags->tab[3])
	{
		while (--i >= 2)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len + 2] = '0';
	}
	else
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len] = ' ';
	}
}

void		long_to_hex(long n, t_flags *flags)
{
	int				len;
	unsigned long	tmp;

	len = 3;
	tmp = (unsigned long)n;
	while (tmp >= 16)
	{
		tmp = tmp / 16;
		len++;
	}
	tmp = n;
	flags->buf[len] = '\0';
	while (--len > 2)
	{
		flags->buf[len] = tmp % 16 > 9 ? tmp % 16 - 10 + 'a' : tmp % 16 + 48;
		tmp = tmp / 16;
	}
	flags->buf[len] = tmp > 9 ? tmp - 10 + 'a' : tmp + 48;
	flags->buf[len - 1] = 'x';
	flags->buf[len - 2] = '0';
}

void		va_putpointeur(va_list ap, t_flags *flags)
{
	long n;

	n = va_arg(ap, long);
	long_to_hex(n, flags);
	if (flags->tab[4] && flags->tab[11])
		do_precision(flags);
	else if (flags->tab[4])
		flags->buf[2] = '\0';
	if (flags->tab[10] && flags->tab[2])
		do_minus(flags);
	else if (flags->tab[10])
		do_length(flags);
}
