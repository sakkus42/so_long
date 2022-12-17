/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:45:39 by sakkus            #+#    #+#             */
/*   Updated: 2022/11/26 16:45:41 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_file_name(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[len - 4] == '.' && str[len - 3] == 'b' && str[len - 2] == 'e'
		&& str[len - 1] == 'r')
		return (0);
	perror("file extension should be '.ber'\n");
	return (1);
}
