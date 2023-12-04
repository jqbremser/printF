/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:04:56 by jbremser          #+#    #+#             */
/*   Updated: 2023/12/04 11:44:36 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *s, int *check)
{
	int	count;

	count = 0;
	if (!s)
		return (print_str("(null)", check));
	while (*s)
		count += print_ch(*s++, check);
	return (count);
}
