/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:45:25 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:45:26 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->line_count)
	{
		free(arg->map[i]);
		i++;
	}
	free(arg->map);
}

int	ft_exit(t_arg *arg)
{
	mlx_clear_window(arg->mlx, arg->mlx_win);
	mlx_destroy_image(arg->mlx, arg->img_back);
	mlx_destroy_image(arg->mlx, arg->img_wall);
	mlx_destroy_image(arg->mlx, arg->img_player);
	mlx_destroy_image(arg->mlx, arg->img_collec);
	ft_free_map(arg);
	exit(0);
	return (0);
}
