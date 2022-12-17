/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:18:58 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/18 17:19:00 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_numb_of_elem(t_arg *arg)
{
	ft_numb_of_elem_check(arg);
	if (arg->p_count != 1 || arg->e_count != 1 || arg->c_count == 0)
	{
		perror("the number of elements is wrong!!!\n");
		return (1);
	}
	return (0);
}

int	ft_rectangle_check(t_arg *arg)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(arg->map[0]);
	y = 0;
	while (y < arg->line_count)
	{
		x = 0;
		while (arg->map[y] && arg->map[y][x] != '\n' \
			&& x < (int)(ft_strlen(arg->map[y])))
			x++;
		if (x != len - 1)
		{
			ft_printf("%dth Line:", y + 1);
			perror("Rectangle Error\n");
			return (1);
		}
		y++;
	}
	return (0);
}

int	ft_wall_check(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x] && arg->map[y][x] != '\n')
		{
			if (((y == 0 || y == arg->line_count - 1) || (x == 0
						|| (size_t)x == ft_strlen(arg->map[y]) - 2))
				&& arg->map[y][x] != '1')
			{
				ft_printf("%dth line %dth character => %c ", y + 1, x + 1, \
						arg->map[y][x]);
				perror("WALL ERROR!!\n");
				return (1);
			}
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	ft_map_element_check(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x] != '\0' && arg->map[y][x] != '\n')
		{
			if (ft_strchr(MAP_CHAR, arg->map[y][x]))
				x++;
			else
			{
				ft_printf("%c ->", arg->map[y][x]);
				perror(" invalid character!!\n");
				return (1);
			}
		}
		y++;
	}
	return (0);
}

int	ft_check_map(t_arg *arg, char *str)
{
	int	i;

	i = 0;
	ft_read_map(arg, str);
	if (!(arg->map))
	{
		perror("file could not be read!!\n");
		return (1);
	}
	if (ft_rectangle_check(arg) || ft_map_element_check(arg)
		|| ft_numb_of_elem(arg) || ft_wall_check(arg) || ft_valid(arg))
	{
		ft_free_map(arg);
		return (1);
	}
	ft_free_map(arg);
	return (0);
}
