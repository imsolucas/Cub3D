/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:43:32 by djin              #+#    #+#             */
/*   Updated: 2023/06/06 21:52:50 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_upper(unsigned int n, int *len)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (n >= 16)
	{
		print_hex_upper(n / 16, len);
		print_hex_upper(n % 16, len);
	}
	else
	{
		*len += write(1, &str[n], 1);
	}
}

void	print_hex(unsigned int n, int *len)
{
	char	*str;

	str = "0123456789abcdef";
	if (n >= 16)
	{
		print_hex(n / 16, len);
		print_hex(n % 16, len);
	}
	else
	{
		*len += write(1, &str[n], 1);
	}
}

void	ptr_hex(unsigned long long n, int *len)
{
	char	*str;

	str = "0123456789abcdef";
	if (n >= 16)
	{
		ptr_hex(n / 16, len);
		ptr_hex(n % 16, len);
	}
	else
	{
		*len += write(1, &str[n], 1);
	}
}

void	print_ptr(unsigned long long n, int *len)
{
	*len += ft_put_char('0');
	*len += ft_put_char('x');
	ptr_hex(n, len);
}
