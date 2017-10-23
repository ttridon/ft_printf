/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 15:42:41 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/09 17:09:39 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

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
			if (flags->tab[3])
				flags->buf[len] = '0';
			else
				flags->buf[len] = ' ';
	}
}

static void	do_length_bis(t_flags *flags)
{
	int i;
	int len;

	i = ft_strlen(flags->buf);
	len = flags->tab[10] - i;
	if (flags->tab[2])
	{
		write(1, "\0", 1);
		while (i++ < flags->tab[10] && flags->tab[12]++)
			write(1, " ", 1);
	}
	else
	{
		while (--len >= 0)
		{
			if (flags->tab[3])
				write(1, "0", 1);
			else
				write(1, " ", 1);
			flags->tab[12]++;
		}
		write(1, "\0", 1);
	}
}

void		va_putchar(va_list ap, t_flags *flags)
{
	char	c;

	if (flags->tab[7])
	{
		va_putmchar(ap, flags);
		return ;
	}
	c = va_arg(ap, int);
	if (!c)
	{
		flags->tab[12]++;
		flags->tab[10]--;
		do_length_bis(flags);
	}
	else
	{
		flags->buf[0] = c;
		if (flags->tab[10])
			do_length(flags);
	}
}
