/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:43:45 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:44:06 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_exit(WRONG_FILE);
	return (fd);
}
