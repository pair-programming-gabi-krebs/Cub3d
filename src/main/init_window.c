/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:42:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/01 05:02:43 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	load_images(t_cube *cube);
static void	map_mock(t_cube *cube);

void	init_window(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx_ptr, 10 * SIZE_IMG, 10 * SIZE_IMG, "Cub3D");
	load_images(cube);
	map_mock(cube);
}

static void	load_images(t_cube *cube)
{
	cube->player.testeImg = mlx_xpm_file_to_image(cube->mlx_ptr, TESTE_IMG, &(cube->player.img_width), &(cube->player.img_height));
	cube->player.paredeImg = mlx_xpm_file_to_image(cube->mlx_ptr, PAREDE, &(cube->player.img_width), &(cube->player.img_height));
	cube->player.personagemImg = mlx_xpm_file_to_image(cube->mlx_ptr, PERSONAGEM, &(cube->player.img_width), &(cube->player.img_height));
}

static void	map_mock(t_cube *cube)
{
	int	i;

	cube->map = malloc(sizeof(char **) * 11);
	cube->map[10] = NULL;
	cube->map[0] = ft_strdup("1111111111");
	i = 1;
	while (i < 9)
	{
		cube->map[i] = ft_strdup("1000000001");
		i++;
	}
	cube->map[9] = ft_strdup("1111111111");
	free(cube->map[2]);
	free(cube->map[4]);
	free(cube->map[6]);
	cube->map[2] = ft_strdup("1111110001");
	cube->map[4] = ft_strdup("1000N00001");
	cube->map[6] = ft_strdup("1001111111");
}