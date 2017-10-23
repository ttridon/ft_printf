/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:40:55 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/22 20:37:13 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_strdup(const char *s1, t_flags *flags)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen((char *)s1);
	while (s1[i])
	{
		flags->buf[i] = s1[i];
		i++;
	}
	flags->buf[i] = '\0';
}
