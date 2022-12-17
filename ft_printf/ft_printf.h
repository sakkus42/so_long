/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:38:39 by sakkus            #+#    #+#             */
/*   Updated: 2022/07/31 18:42:48 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_print_ptr_adress(size_t x, int *pn);
void	ft_print_str(char *str, int *pn);
void	ft_putchar(char c, int *pn);
void	ft_print_char(va_list ar, int *pn);
void	ft_print_unsigned(unsigned int x, int *pn);
void	ft_print_hex(unsigned int n, int *pn, char type);
void	ft_print_decimal_number(int nb, int *pn);

#endif
