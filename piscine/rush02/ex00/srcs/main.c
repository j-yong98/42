/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeychoi <jaeychoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:19:46 by jaeychoi          #+#    #+#             */
/*   Updated: 2023/01/30 19:27:33 by jaeychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mynums.h"

int	exec(char *num, t_mynums *head, char *file_path)
{
	head = make_dict(read_dict(file_path));
	if (head == 0)
		print_error("Dict Error\n");
	else
		print_num(num, head->next);
	free_dict(head);
	return (1);
}

int	main(int argc, char **argv)
{
	char		*file_path;
	char		*num;
	t_mynums	*head;

	if (argc == 1 || argc > 3)
	{
		print_error("Error\n");
		return (0);
	}
	else if (argc == 2)
	{
		file_path = "numbers.dict";
		num = argv[1];
	}
	else if (argc == 3)
	{
		printf("%s\n", argv[1]);
		file_path = argv[1];
		num = argv[2];
	}
	if (*(arg_check(num)) == 0)
		print_error("Error\n");
	else
		exec(num, head, file_path);
	return (0);
}
