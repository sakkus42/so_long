/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:46:51 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:46:53 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_line_len(t_arg *arg, char *str)
{
	int		fd;
	int		len;
	char	c;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		arg->line_count = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	close(fd);
	len++;
	arg->map = malloc(sizeof(char *) * len + 1);
	if (!arg->map)
		return ;
	arg->map[len + 1] = NULL;
	arg->line_count = len;
}

void	ft_read_map(t_arg *arg, char *str)
{
	int	fd;
	int	i;

	ft_line_len(arg, str);
	if (arg->line_count <= 0 || !(arg->map))
	{
		arg->map = NULL;
		return ;
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(arg->map);
		return ;
	}
	i = 0;
	arg->map[i] = get_next_line(fd);
	while (arg->map[i])
	{
		i++;
		arg->map[i] = get_next_line(fd);
	}
	close(fd);
}
