/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:05:17 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/23 16:12:22 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n, char *s)
{
	unsigned int	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb >= 10 && len++)
		nb = nb / 10;
	while (--len >= 0)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_hhuitoa(unsigned char n, char *s)
{
	unsigned char	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb >= 10 && len++)
		nb = nb / 10;
	while (--len >= 0)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_huitoa(unsigned short n, char *s)
{
	unsigned short	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb >= 10 && len++)
		nb = nb / 10;
	while (--len >= 0)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_luitoa(unsigned long n, char *s)
{
	unsigned long	nb;
	int				len;

	len = 1;
	nb = n;
	while (nb >= 10 && len++)
		nb = nb / 10;
	while (--len >= 0)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

char	*ft_lluitoa(unsigned long long n, char *s)
{
	unsigned long long	nb;
	int					len;

	len = 1;
	nb = n;
	while (nb >= 10 && len++)
		nb = nb / 10;
	while (--len >= 0)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
