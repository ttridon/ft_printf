/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putmusnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 14:42:38 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/04 15:15:07 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_precision(t_flags *flags)
{
	int i;
	int len;
	int tmp;

	i = ft_strlen(flags->buf);
	len = flags->tab[11] - i;
	tmp = 0;
	if (flags->buf[0] == '+' || flags->buf[0] == '-')
	{
		tmp = 1;
		len++;
	}
	if (len > 0)
	{
		while (--i >= tmp)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len + tmp] = '0';
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
	int	len;
	int	tmp;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (len <= 0)
		return ;
	if (flags->tab[3])
	{
		tmp = flags->tab[0] ? 2 : 0;
		while (--i >= tmp)
			flags->buf[i + len] = flags->buf[i];
		while (--len + tmp >= tmp)
			flags->buf[len + tmp] = '0';
	}
	else
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len] = ' ';
	}
}

void		va_putmusnbr(va_list ap, t_flags *flags)
{
	unsigned long long n;

	n = va_arg(ap, unsigned long long);
	ft_luitoa(n, flags->buf);
	if (flags->tab[4] && flags->tab[11] == 0 && n == 0)
		ft_bzero(flags->buf, ft_strlen(flags->buf));
	else
		do_precision(flags);
	if (flags->tab[10] && flags->tab[2])
		do_minus(flags);
	else if (flags->tab[10])
		do_length(flags);
}
