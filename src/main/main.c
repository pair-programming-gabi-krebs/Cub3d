/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:46:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/16 23:41:06 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	main(int argc, char **argv)
{
    int a = argc;
	t_cube	cube;
    file_validations(&cube, argv[1]);
    return (a);
}
