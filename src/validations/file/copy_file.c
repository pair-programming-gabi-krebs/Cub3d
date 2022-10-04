/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:29:36 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:29:48 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	copy_file(t_cube *cube, char *file)
{
	char	*line;
	int		lines;
	int		fd;
	int		i;

	lines = count_lines(file);
	cube->content.total_lines = lines;
	cube->content.content = malloc(sizeof(char*) * (lines + 1));
	fd = open_file(file);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		cube->content.content[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	cube->content.content[i] = NULL;
}
