/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:59:30 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/11/11 10:59:49 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(long n);
int		ft_print_hexa(unsigned long value, char format);
int		ft_print_num(int num);
int		ft_print_ptr(unsigned long ptr, char format);
int		ft_print_str(char *str);
int		ft_printf(const char *str, ...);
int		ft_putchar(char s);
int		ft_un_num(unsigned int num);

#endif
