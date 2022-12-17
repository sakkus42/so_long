/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:27:41 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/31 17:08:21 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsnbr(unsigned int x, int *pn)
{
	if (x >= 10)
	{
		ft_putunsnbr(x / 10, pn);
		ft_putunsnbr(x % 10, pn);
	}
	else
		ft_putchar(x + '0', pn);
}

void	ft_print_unsigned(unsigned int x, int *pn)
{
	ft_putunsnbr(x, pn);
}
