/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:59:09 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 11:05:07 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 1000000

# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	char		buf[BUFF_SIZE];
	int			tab[13];
}				t_flags;

extern void		(*g_fonction[128])(va_list ap, t_flags *flags);

void			ft_putchar(char c);
void			ft_strdup(const char *s1, t_flags *flags);
void			ft_bzero(void *s, size_t n);
void			va_putbinaire(va_list ap, t_flags *flags);
void			va_putchar(va_list ap, t_flags *flags);
void			va_putmchar(va_list ap, t_flags *flags);
void			va_putstr(va_list ap, t_flags *flags);
void			va_putmstr(va_list ap, t_flags *flags);
void			va_putnbr(va_list ap, t_flags *flags);
void			va_putmnbr(va_list ap, t_flags *flags);
void			va_puthexa(va_list ap, t_flags *flags);
void			va_putmhexa(va_list ap, t_flags *flags);
void			va_putoctal(va_list ap, t_flags *flags);
void			va_putmoctal(va_list ap, t_flags *flags);
void			va_putpointeur(va_list ap, t_flags *flags);
void			va_putusnbr(va_list ap, t_flags *flags);
void			va_putmusnbr(va_list ap, t_flags *flags);
void			va_percent(va_list ap, t_flags *flags);
char			*ft_itoa(int n, char *s);
char			*ft_hitoa(short n, char *s);
char			*ft_hhitoa(char n, char *s);
char			*ft_litoa(long n, char *s);
char			*ft_llitoa(long long n, char *s);
char			*ft_uitoa(unsigned int n, char *s);
char			*ft_huitoa(unsigned short n, char *s);
char			*ft_hhuitoa(unsigned char n, char *s);
char			*ft_luitoa(unsigned long n, char *s);
char			*ft_lluitoa(unsigned long long n, char *s);
char			*ft_itoa_base(unsigned int n, int base, char *s);
char			*ft_hitoa_base(unsigned short n, int base, char *s);
char			*ft_hhitoa_base(unsigned char n, int base, char *s);
char			*ft_litoa_base(unsigned long n, int base, char *s);
char			*ft_llitoa_base(unsigned long long n, int base, char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_atoi(char **s);
int				ft_printf(char *format, ...);
int				ft_putstr(char *s);
int				ft_toupper(int c);
int				str_toupper(char *s);
long			ft_puissance(int n, int p);
size_t			ft_strlen(const char *s);

#endif
