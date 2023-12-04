/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:33:46 by jbremser          #+#    #+#             */
/*   Updated: 2023/12/04 12:01:46 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pickme(char picker, va_list arg, int *check)
{
	int	count;

	count = 0;
	if (picker == 'c')
		count = print_ch(va_arg(arg, int), check);
	else if (picker == 's')
		count = print_str(va_arg(arg, char *), check);
	else if (picker == 'p')
		count = printp(((unsigned long int)va_arg(arg, void *)), check);
	else if (picker == 'd')
		count = cast_dec(va_arg(arg, int), check);
	else if (picker == 'i')
		count = cast_dec(va_arg(arg, int), check);
	else if (picker == 'u')
		count = cast_hex(va_arg(arg, unsigned int), 10, 0, check);
	else if (picker == 'x')
		count = cast_hex(va_arg(arg, unsigned int), 16, 0, check);
	else if (picker == 'X')
		count = cast_hex(va_arg(arg, unsigned int), 16, 1, check);
	else
		count = print_ch(picker, check);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;
	int		tempcount;
	int		check;

	va_start(arg, s);
	count = 0;
	check = 0;
	while (*s)
	{
		tempcount = 0;
		if (*s == '%')
		{
			++s;
			tempcount += pickme(*s++, arg, &check);
		}
		else
			tempcount += write(1, s++, 1);
		if (tempcount < 0)
			return (-1);
		count += tempcount;
	}
	va_end(arg);
	return (count);
}
