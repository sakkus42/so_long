/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:43 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/22 15:41:47 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char *arv[])
{
	t_arg	arg;

	if (arc != 2)
	{
		perror("ERROR: missing arg!!!\n");
		return (1);
	}
	if (ft_file_name(arv[1]) || ft_check_map(&arg, arv[1]))
		return (1);
	if (ft_map_init(&arg, arv[1]))
		return (1);
	return (0);
}
