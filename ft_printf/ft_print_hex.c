/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:19:58 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/31 17:21:25 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, int *pn, char type)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, pn, type);
		ft_print_hex(n % 16, pn, type);
	}
	if (n < 16)
	{
		if (n > 9 && type == 'X')
			ft_putchar(n - 10 + 'A', pn);
		if (n > 9 && type == 'x')
			ft_putchar(n - 10 + 'a', pn);
		if (n < 10)
			ft_putchar(n + '0', pn);
	}
}
