/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 13:53:50 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 13:18:08 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void (*g_fonction[128])(va_list ap, t_flags *flags) = {
	['b'] = va_putbinaire,
	['c'] = va_putchar,
	['C'] = va_putmchar,
	['d'] = va_putnbr,
	['D'] = va_putmnbr,
	['i'] = va_putnbr,
	['o'] = va_putoctal,
	['O'] = va_putmoctal,
	['p'] = va_putpointeur,
	['s'] = va_putstr,
	['S'] = va_putmstr,
	['u'] = va_putusnbr,
	['U'] = va_putmusnbr,
	['x'] = va_puthexa,
	['X'] = va_putmhexa,
	['%'] = va_percent
};

static int	check_flags(char **s, t_flags *flags)
{
	int			i;
	static char	cmp[] = "#+-0. hljz";

	i = 12;
	while (--i >= 0)
		flags->tab[i] = 0;
	while (g_fonction[(int)(**s)] == NULL)
	{
		if (ft_strchr(cmp, **s) != NULL)
		{
			flags->tab[ft_strchr(cmp, **s) - cmp] += 1;
			if (**s == '.' && (*s)++)
				flags->tab[11] = ft_atoi(s);
		}
		else if (**s >= '0' && **s <= '9')
			flags->tab[10] = ft_atoi(s);
		else
		{
			(*s)--;
			return (0);
		}
		(*s)++;
	}
	return (1);
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, format);
	flags.tab[12] = 0;
	while (*format)
	{
		if (*format == '%' && format++)
		{
			ft_bzero(flags.buf, BUFF_SIZE);
			if (check_flags(&format, &flags))
				g_fonction[(int)(*format)](ap, &flags);
			flags.tab[12] = flags.tab[12] + ft_putstr(flags.buf);
		}
		else
		{
			write(1, format, 1);
			flags.tab[12]++;
		}
		format++;
	}
	va_end(ap);
	return (flags.tab[12]);
}
