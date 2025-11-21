/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <so-ait-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:43:07 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/21 16:50:51 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line2 ;
	char	*line3 ;
	char	*line1;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	line1 = get_next_line_bonus(fd1);
	line2 = get_next_line_bonus(fd2);
	line3 = get_next_line_bonus(fd3);
	while (line1 != NULL)
	{
		printf("File1: %s", line1);
		free(line1);
		line1 = get_next_line_bonus(fd1);
	}
	while (line2 != NULL)
	{
		printf("File2: %s", line2);
		free(line2);
		line2 = get_next_line_bonus(fd2);
	}
	while (line3 != NULL)
	{
		printf("File3: %s", line3);
		free(line3);
		line3 = get_next_line_bonus(fd3);
	}
	close(fd3);
	close(fd2);
	close(fd1);
	return (0);
}
