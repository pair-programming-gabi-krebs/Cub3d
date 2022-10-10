/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:27:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/06 00:48:20 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_border_line(char *line)
{
	int	len;

	len = ft_strlen(line) - 1;
	if ((!line[0] || !line[len - 1]) || (line[0] != '1' || \
		line[len] != '1'))
	{
		free(line);
		return (1);
	}
	return (0);
}
