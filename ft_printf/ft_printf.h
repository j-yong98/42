/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:33:52 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/03/22 14:05:32 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	conversion(const char type, va_list ptr);
int	ft_print_hex(unsigned int num, int classify);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_decimal(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_putch(int c);
int	ft_puts(char *str);
#endif
