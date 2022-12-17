/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:16:46 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/29 18:16:48 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define MAP_CHAR "01ECP"

typedef struct s_arg
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img_back;
	void	*img_wall;
	void	*img_collec;
	void	*img_player;
	void	*img_exit;
	int		width;
	int		high;
	int		line_count;
	int		p_count;
	int		c_count;
	int		e_count;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
}			t_arg;

int			ft_check_map(t_arg *arg, char *str);
void		ft_read_map(t_arg *arg, char *str);
int			ft_file_name(char *str);
int			ft_map_element_check(t_arg *arg);
int			ft_map_location_check(t_arg *arg);
void		ft_free_map(t_arg *arg);
int			ft_valid(t_arg *arg);
int			ft_map_init(t_arg *arg, char *str);
char		*ft_itoa(int n);
int			ft_exit(t_arg *arg);
void		ft_numb_of_elem_check(t_arg *arg);
void		ft_put(t_arg *arg, void *img, int x, int y);

#endif