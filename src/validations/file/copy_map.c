/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:38:51 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 03:05:08 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	copy_map(t_cube *cube, int line)
{
	int	i;
	
	cube->map.map = malloc(sizeof(char*) * (cube->content.total_lines + 1));
	i = 0;
	while (cube->content.content[line])
	{
		cube->map.map[i] = ft_strdup(cube->content.content[line]);
		i++;
		line++;
	}
	cube->map.map[i] = NULL;
}
