/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:03:24 by jbremser          #+#    #+#             */
/*   Updated: 2023/12/04 12:02:07 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	print_ch(char c, int *check);
int	print_str(char *s, int *check);
int	cast_hex(unsigned long long n, unsigned int base, int x, int *check);
int	cast_dec(int n, int *check);
int	printp(unsigned long int s, int *check);
#endif
