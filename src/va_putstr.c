/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:11:57 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/09 17:36:11 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	do_length(t_flags *flags)
{
	int i;
	int	len;

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

void		va_putstr(va_list ap, t_flags *flags)
{
	char	*s;
	int		i;
	int		max;

	if ((i = -1) && flags->tab[7])
	{
		va_putmstr(ap, flags);
		return ;
	}
	if ((s = va_arg(ap, char *)))
	{
		max = flags->tab[4] ? flags->tab[11] : ft_strlen(s);
		while (s[++i] && i < max)
			flags->buf[i] = s[i];
		if (flags->tab[10] && flags->tab[10] > (int)ft_strlen(flags->buf))
			do_length(flags);
	}
	else if ((i = 6))
	{
		if (flags->tab[4])
			i = flags->tab[11] > 6 ? 6 : flags->tab[11];
		ft_strncpy(flags->buf, "(null)", i);
		if (flags->tab[10] && flags->tab[10] > (int)ft_strlen(flags->buf))
			do_length(flags);
	}
}
