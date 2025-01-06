/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:15:17 by djin              #+#    #+#             */
/*   Updated: 2023/06/06 20:06:34 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *str, ...);
void	print_ptr(unsigned long long n, int *len);
void	print_hex(unsigned int n, int *len);
void	print_hex_upper(unsigned int n, int *len);
int		ft_put_char(char c);
void	ft_put_str(char *str, int *len);
void	print_unsigned(unsigned int n, int *len);
int		put_nbr(int n, int *len);

#endif