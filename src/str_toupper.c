/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_toupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:52:27 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/09 17:13:16 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		str_toupper(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (1);
}
