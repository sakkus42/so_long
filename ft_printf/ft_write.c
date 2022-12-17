/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:53:43 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/31 18:38:27 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *pn)
{
	*pn += 1;
	write(1, &c, 1);
}

void	ft_print_str(char *str, int *pn)
{	
	int		i;

	if (!str)
	{
		ft_print_str("(null)", pn);
		return ;
	}
	i = 0;
	while (str[i])
	{
		*pn += 1;
		write(1, &str[i], 1);
		i++;
	}
}
