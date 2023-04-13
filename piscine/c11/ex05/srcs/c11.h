/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c11.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:55:59 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/31 11:52:07 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C11_H
# define C11_H

# include <unistd.h>

int		ft_atoi(char *str);
void	ft_print(int num);
void	calc(char *s1, char *s2, char *op);
int		add(int s1, int s2);
int		sub(int s1, int s2);
int		mod(int s1, int s2);
int		mul(int s1, int s2);
int		div(int s1, int s2);
#endif
