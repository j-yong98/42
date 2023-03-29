/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelee2 <jelee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:03:00 by jelee2            #+#    #+#             */
/*   Updated: 2023/01/31 14:46:02 by jelee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRING_H
# define MY_STRING_H

# include "my_string2.h"

int		my_strlen(char *str);
void	my_strcpy(char *dst, char *src);
int		my_linelen(char *str);
void	my_linecpy(char *dst, char *src);
int		my_linetoi(char *str, int n);

#endif
