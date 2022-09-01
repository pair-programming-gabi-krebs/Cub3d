/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:46:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 03:11:36 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	main(int argc, char **argv)
{
	t_cube	cube;
	
    file_validations(&cube, argc, argv[1]);
	init_window(&cube);
	game(&cube);
    return (0);
}
