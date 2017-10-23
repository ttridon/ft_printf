/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putmstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 11:18:29 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 13:16:32 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <wchar.h>
#include <stdio.h>

static void	do_length(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (flags->tab[2])
	{
		while (i < flags->tab[10])
			if (flags->tab[3])
				flags->buf[i++] = ' ';
	}
	else
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			if (flags->tab[3])
				flags->buf[len] = '0';
			else
				flags->buf[len] = ' ';
	}
}

static int	count_bits(wint_t c)
{
	int i;

	i = 1;
	while ((c = c >> 1))
		i++;
	return (i);
}

static void	ft_putwchar(wint_t c, char *buf)
{
	int i;
	int nbit;

	i = 0;
	nbit = count_bits(c);
	if (nbit > 7)
	{
		if (nbit > 11)
		{
			if (nbit > 16)
			{
				buf[i++] = ((c >> 18) & 0x7) | 0xf0;
				buf[i++] = ((c >> 12) & 0x3f) | 0x80;
			}
			else
				buf[i++] = ((c >> 12) & 0xf) | 0xe0;
			buf[i++] = ((c >> 6) & 0x3f) | 0x80;
		}
		else
			buf[i++] = ((c >> 6) & 0x1f) | 0xc0;
		buf[i++] = (c & 0x3f) | 0x80;
	}
	else
		buf[i] = c;
}

void		va_putmstr(va_list ap, t_flags *flags)
{
	int		i;
	int		max;
	wchar_t	*s;

	i = -1;
	if (!(s = va_arg(ap, wchar_t *)))
	{
		i = 6;
		if (flags->tab[4])
			i = flags->tab[11] > 6 ? 6 : flags->tab[11];
		write(1, "(null)", i);
		flags->tab[12] = flags->tab[12] + i;
		if (i == 118)
			ft_strncpy(flags->buf, "(null)", i);
	}
	else
	{
		max = flags->tab[4] ? flags->tab[11] : 1000000;
		while (s[++i] && i < max)
			ft_putwchar(s[i], &flags->buf[ft_strlen(flags->buf)]);
	}
	if (flags->tab[10] && !flags->tab[4])
		do_length(flags);
}
