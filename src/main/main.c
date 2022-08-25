/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:46:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/24 21:09:21 by gcosta-d         ###   ########.fr       */
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
