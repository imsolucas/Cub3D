/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:50:29 by djin              #+#    #+#             */
/*   Updated: 2023/06/06 20:23:10 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		*len += write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		*len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		put_nbr(n / 10, len);
		put_nbr(n % 10, len);
	}
	else
	{
		n += '0';
		*len += write (1, &n, 1);
	}
	return (0);
}

void	print_unsigned(unsigned int n, int *len)
{
	if (n >= 10)
	{
		put_nbr(n / 10, len);
		put_nbr(n % 10, len);
	}
	else
	{
		n += '0';
		*len += write (1, &n, 1);
	}
}
