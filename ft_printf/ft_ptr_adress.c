/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:46:49 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/31 12:46:51 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_conver(size_t x, int *pn)
{
	if (x >= 16)
	{
		ft_hex_conver(x / 16, pn);
		ft_hex_conver(x % 16, pn);
	}
	if (x < 16)
	{
		if (x < 10)
			ft_putchar(x + '0', pn);
		else
			ft_putchar(x - 10 + 'a', pn);
	}
}

void	ft_print_ptr_adress(size_t x, int *pn)
{
	*pn += 2;
	write(1, "0x", 2);
	if (x == 0)
		ft_putchar('0', pn);
	else
		ft_hex_conver(x, pn);
}
