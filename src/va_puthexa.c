/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:26:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/09 16:58:52 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_precision(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[11] - i;
	if (len > 0)
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len] = '0';
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
	if (flags->tab[3] && !flags->tab[4])
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

static void	do_dieze(t_flags *flags)
{
	int	i;

	i = ft_strlen(flags->buf);
	while (--i >= 0)
		flags->buf[i + 2] = flags->buf[i];
	flags->buf[0] = '0';
	flags->buf[1] = 'x';
}

void		va_puthexa(va_list ap, t_flags *flags)
{
	unsigned long long	n;

	n = va_arg(ap, unsigned long long);
	if (n == 0)
		flags->tab[0] = 0;
	if (flags->tab[6] == 2)
		ft_hhitoa_base(n, 16, flags->buf);
	else if (flags->tab[6] == 1)
		ft_hitoa_base(n, 16, flags->buf);
	else if (flags->tab[7] == 1 || flags->tab[8] == 1)
		ft_litoa_base(n, 16, flags->buf);
	else if (flags->tab[7] == 2 || flags->tab[9] == 1)
		ft_llitoa_base(n, 16, flags->buf);
	else
		ft_itoa_base(n, 16, flags->buf);
	if (flags->tab[4] && flags->tab[11] == 0 && n == 0)
		ft_bzero(flags->buf, ft_strlen(flags->buf));
	else
		do_precision(flags);
	if (flags->tab[0])
		do_dieze(flags);
	if (flags->tab[10] && flags->tab[2])
		do_minus(flags);
	else if (flags->tab[10])
		do_length(flags);
}
