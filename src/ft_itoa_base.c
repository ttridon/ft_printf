/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:24:14 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/25 17:22:24 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned int n, int base, char *s)
{
	unsigned int	nb;
	int				len;

	len = n > 0 ? 0 : 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n, s));
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}

char	*ft_hitoa_base(unsigned short n, int base, char *s)
{
	unsigned short	nb;
	int				len;

	len = n > 0 ? 0 : 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n, s));
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}

char	*ft_hhitoa_base(unsigned char n, int base, char *s)
{
	unsigned char	nb;
	int				len;

	len = n > 0 ? 0 : 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n, s));
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}

char	*ft_litoa_base(unsigned long n, int base, char *s)
{
	unsigned long	nb;
	int				len;

	len = n > 0 ? 0 : 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n, s));
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}

char	*ft_llitoa_base(unsigned long long n, int base, char *s)
{
	unsigned long long	nb;
	int					len;

	len = n > 0 ? 0 : 1;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n, s));
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}
