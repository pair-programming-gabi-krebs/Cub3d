/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:46:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/10/12 01:45:28 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	ft_init(&cube);
	file_validations(&cube, argc, argv[1]);
	init_window(&cube);
	game(&cube);
	return (0);
}
