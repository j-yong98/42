/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:16:36 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/04/11 21:45:58 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valid_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error("No such file or directory");
	close(fd);
}

void	valid_extension(char *filename)
{
	const char	*ext;
	size_t		len;

	ext = "fdf";
	len = ft_strlen(filename);
	len -= 3;
	while (*(filename + len))
	{
		if (*ext != *(filename + len))
			ft_error("invalid file extension");
		len++;
		ext++;
	}
}

int	validate(char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(split + i))
	{
		j = 0;
		if (**(split + i) == '-')
			j++;
		if (!*(*(split + i) + j))
			return (0);
		while (*(*(split + i) + j))
		{
			if (!ft_isdigit(*(*(split + i) + j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
