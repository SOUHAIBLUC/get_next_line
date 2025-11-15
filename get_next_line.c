/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: so-ait-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:27:27 by so-ait-l          #+#    #+#             */
/*   Updated: 2025/11/15 17:27:30 by so-ait-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *reminder;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
        line = read_line(fd, reminder);
    if (!line)
        return (NULL);
