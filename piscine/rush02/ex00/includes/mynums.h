/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mynums.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooypark <jooypark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:06:09 by jooypark          #+#    #+#             */
/*   Updated: 2023/01/30 11:32:12 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYNUMS_H
# define MYNUMS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_mynums{
	char			*key;
	char			*value;
	struct s_mynums	*next;
}	t_mynums;

int			print_key(char *num, t_mynums *dict);
int			check_key_exist(char *num, t_mynums *dict);
int			len(char *str);
int			check_all_zero(char *num);
char		*make_num_front(char *num, int num_len);
char		*parse_num(char *num, int num_len, t_mynums *dict);
void		print_num(char *num, t_mynums *dict);
void		pos_hundred(char *num, t_mynums *dict);
void		pos_ten(char *num, t_mynums *dict);
void		pos_one(char *num, t_mynums *dict);
t_mynums	*make_dict(char *dict);
char		*read_dict(char *file_path);
int			is_space(char ch);
void		print_error(char *str);
char		*arg_check(char *arg);
int			is_validate_key(char *key);
void		free_dict(t_mynums *cur);
#endif
