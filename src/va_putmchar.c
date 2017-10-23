/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putmchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 17:25:32 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 10:55:30 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <wchar.h>

static void	do_length(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (flags->tab[2])
		while (i < flags->tab[10])
			flags->buf[i++] = ' ';
	else
	{
		while (--i >= 0)
			flags->buf[i + len] = flags->buf[i];
		while (--len >= 0)
			flags->buf[len] = ' ';
	}
}

void		do_length_bis(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (flags->tab[2])
	{
		write(1, "\0", 1);
		while (i < flags->tab[10])
		{
			write(1, " ", 1);
			flags->tab[12]++;
			i++;
		}
	}
	else
	{
		while (--len >= 0)
		{
			write(1, " ", 1);
			flags->tab[12]++;
		}
		write(1, "\0", 1);
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

void		va_putmchar(va_list ap, t_flags *flags)
{
	wint_t	c;

	c = va_arg(ap, wint_t);
	if (!c)
	{
		flags->tab[12]++;
		flags->tab[10]--;
		do_length_bis(flags);
	}
	else
	{
		ft_putwchar(c, flags->buf);
		if (flags->tab[10])
			do_length(flags);
	}
}
