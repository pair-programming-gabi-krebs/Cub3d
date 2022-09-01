/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:46:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 23:47:36 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	file_validations(&cube, argc, argv[1]);
	init_window(&cube);
	return (0);
}
