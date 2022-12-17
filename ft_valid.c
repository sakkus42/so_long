/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:47:02 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:47:04 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_point_change(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == '0')
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	ft_recursive_map(t_arg *arg, int x, int y)
{
	if (arg->map[y][x - 1] != '1' && arg->map[y][x - 1] != 'P' \
		&& arg->map[y][x - 1] != 'E')
	{
		arg->map[y][x - 1] = 'P';
		ft_recursive_map(arg, x - 1, y);
	}
	if (arg->map[y][x + 1] != '1' && arg->map[y][x + 1] != 'P' \
		&& arg->map[y][x + 1] != 'E')
	{
		arg->map[y][x + 1] = 'P';
		ft_recursive_map(arg, x + 1, y);
	}
	if (arg->map[y - 1][x] != '1' && arg->map[y - 1][x] != 'P' \
		&& arg->map[y - 1][x] != 'E')
	{
		arg->map[y - 1][x] = 'P';
		ft_recursive_map(arg, x, y - 1);
	}
	if (arg->map[y + 1][x] != '1' && arg->map[y + 1][x] != 'P' \
		&& arg->map[y + 1][x] != 'E')
	{
		arg->map[y + 1][x] = 'P';
		ft_recursive_map(arg, x, y + 1);
	}
	return ;
}

int	ft_control_new_map(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x] && arg->map[y][x] != '\n')
		{
			if (arg->map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_exit_wall(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (arg->map[y][x])
	{
		if (arg->map[y][x] == 'E')
			break ;
		if ((size_t)x == ft_strlen(arg->map[y]) - 2)
		{
			x = 0;
			y++;
		}
		x++;
	}
	if (arg->map[y][x + 1] == 'P' || arg->map[y][x - 1] == 'P' \
		|| arg->map[y - 1][x] == 'P' || arg->map[y + 1][x] == 'P')
		return (0);
	return (1);
}

int	ft_valid(t_arg *arg)
{
	ft_point_change(arg->map);
	ft_recursive_map(arg, arg->player_x, arg->player_y);
	if (ft_control_new_map(arg) || ft_exit_wall(arg))
	{
		perror("Invalid Map!!!\n");
		return (1);
	}
	return (0);
}
