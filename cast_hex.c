/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:36:35 by jbremser          #+#    #+#             */
/*   Updated: 2023/12/04 11:17:57 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cast_hex(unsigned long long n, unsigned int base, int x, int *check)
{
	int		count;
	char	*up;
	char	*low;

	count = 0;
	low = "0123456789abcdef";
	up = "0123456789ABCDEF";
	if (n < 0)
	{
		count += print_ch('-', check);
		count += cast_hex(-(n), base, x, check);
	}
	else if (n > base - 1)
	{
		count += cast_hex(n / base, base, x, check);
		count += cast_hex(n % base, base, x, check);
	}
	else
	{
		if (x == 0)
			count += print_ch(low[n], check);
		else if (x == 1)
			count += print_ch(up[n], check);
	}
	return (count);
}
