/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:53:08 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 18:53:12 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(t_arg *arg, void *img, int x, int y)
{
	mlx_put_image_to_window(arg->mlx, arg->mlx_win, img, \
	64 * x, 64 * y);
}
