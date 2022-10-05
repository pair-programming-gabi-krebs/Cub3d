/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:31:30 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:31:45 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void path_validation(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (strict_strcmp(dot, ".cub"))
		ft_exit(WRONG_EXTENSIONS);
}
