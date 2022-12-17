/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:16:46 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/04 19:07:07 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

long	ft_tmp(long tmp)
{
	if (tmp < 0)
		return (tmp * -1);
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		nlen;
	int		negative;
	char	*str;
	long	tmp;

	tmp = (long)n;
	negative = 0;
	if (n < 0)
		negative = 1;
	nlen = ft_intlen(tmp) + negative;
	str = malloc(sizeof(char) * nlen + 1);
	if (!(str))
		return (NULL);
	*(str + nlen--) = '\0';
	tmp = ft_tmp(tmp);
	while (tmp > 0)
	{
		*(str + nlen--) = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (nlen == 0 && str[1] == '\0')
		*(str + nlen) = '0';
	if (negative)
		str[nlen] = '-';
	return (str);
}
