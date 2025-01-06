/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:05:51 by djin              #+#    #+#             */
/*   Updated: 2023/06/06 21:51:51 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_checker(char c, va_list ap, int *len)
{
	if (c == 'c')
		*len += ft_put_char(va_arg(ap, int));
	else if (c == 's')
		ft_put_str(va_arg(ap, char *), len);
	else if (c == 'p')
		print_ptr(va_arg(ap, unsigned long long), len);
	else if (c == 'd' || c == 'i')
		put_nbr(va_arg(ap, int), len);
	else if (c == 'u')
		print_unsigned(va_arg(ap, unsigned int), len);
	else if (c == 'x')
		print_hex(va_arg(ap, unsigned int), len);
	else if (c == 'X')
		print_hex_upper(va_arg(ap, unsigned int), len);
	else if (c == '%')
		*len += ft_put_char('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printf_checker(str[i], ap, &len);
		}
		else
			len += ft_put_char(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
