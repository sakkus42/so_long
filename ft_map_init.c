/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:46:39 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:46:40 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_creat_xpm(t_arg *arg)
{
	int	x;
	int	y;

	arg->img_back = mlx_xpm_file_to_image(arg->mlx, "./img/back.xpm", &x, &y);
	arg->img_player = mlx_xpm_file_to_image(arg->mlx, "./img/player.xpm", &x,
			&y);
	arg->img_collec = mlx_xpm_file_to_image(arg->mlx, "./img/collec.xpm", &x,
			&y);
	arg->img_wall = mlx_xpm_file_to_image(arg->mlx, "./img/wall.xpm", &x, &y);
	arg->img_exit = mlx_xpm_file_to_image(arg->mlx, "./img/exit.xpm", &x, &y);
	if (!arg->img_back || !arg->img_collec || !arg->img_wall
		|| !arg->img_player)
		return (1);
	return (0);
}

int	ft_window_put_map(t_arg *arg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (arg->map[y][x])
	{
		if (arg->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		if (arg->map[y][x] == '0')
			ft_put(arg, arg->img_back, x, y);
		if (arg->map[y][x] == 'P')
			ft_put(arg, arg->img_player, arg->player_x, arg->player_y);
		if (arg->map[y][x] == '1')
			ft_put(arg, arg->img_wall, x, y);
		if (arg->map[y][x] == 'C')
			ft_put(arg, arg->img_collec, x, y);
		if (arg->map[y][x] == 'E')
			ft_put(arg, arg->img_exit, x, y);
		x++;
	}
	return (0);
}

void	ft_map_mani(t_arg *arg, int x, int y)
{
	if (arg->map[y][x] != '1' && arg->map[y][x] != 'E')
	{
		ft_printf("Action=>%d\n", ++arg->p_count);
		if (arg->map[y][x] == 'C')
			arg->c_count--;
		arg->map[arg->player_y][arg->player_x] = '0';
		arg->map[y][x] = 'P';
		arg->player_x = x;
		arg->player_y = y;
	}
	else if (!arg->c_count && arg->map[y][x] == 'E')
	{
		ft_printf("Action=>%d\n", ++arg->p_count);
		ft_exit(arg);
	}
}

int	ft_action(int key, t_arg *arg)
{
	int		x;
	int		y;
	char	*str;

	x = arg->player_x;
	y = arg->player_y;
	if (key == 13)
		y--;
	else if (key == 1)
		y++;
	else if (key == 2)
		x++;
	else if (key == 0)
		x--;
	else if (key == 53)
		ft_exit(arg);
	else
		return (0);
	mlx_clear_window(arg->mlx, arg->mlx_win);
	ft_map_mani(arg, x, y);
	ft_window_put_map(arg);
	str = ft_itoa(arg->p_count);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, str);
	free(str);
	return (0);
}

int	ft_map_init(t_arg *arg, char *str)
{
	ft_read_map(arg, str);
	arg->p_count = 0;
	arg->mlx = mlx_init();
	arg->mlx_win = mlx_new_window(arg->mlx, 64 * (ft_strlen(arg->map[0]) - 1) \
			, 64 * arg->line_count, "SO_LONG");
	if (!arg->mlx || !arg->mlx_win || ft_creat_xpm(arg))
	{
		perror("mlx failed!!!\n");
		return (1);
	}
	ft_window_put_map(arg);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(arg->mlx_win, 2, 1L << 2, ft_action, arg);
	mlx_hook(arg->mlx_win, 17, 1L << 2, ft_exit, arg);
	mlx_loop(arg->mlx);
	return (0);
}
