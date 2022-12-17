/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:44:58 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:45:04 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_add(t_arg *arg, int x, int y)
{
	arg->player_x = x;
	arg->player_y = y;
}

void	ft_numb_of_elem_check(t_arg *arg)
{
	int	x;
	int	y;

	arg->p_count = 0;
	arg->e_count = 0;
	arg->c_count = 0;
	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x])
		{
			if (arg->map[y][x] == 'P')
			{
				ft_add(arg, x, y);
				arg->p_count++;
			}
			if (arg->map[y][x] == 'E')
				arg->e_count++;
			if (arg->map[y][x] == 'C')
				arg->c_count++;
			x++;
		}
		y++;
	}
}
