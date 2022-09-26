/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:00:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/26 23:58:28 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

//static void	textures(t_cube *cube, char *line);
//static void	check_content(cube, line);
static int	count_lines(char *file);
static int	open_file(char *file);
static void	copy_file(t_cube *cube, char *file);
static int	check_textures(t_cube *cube);
static int	check_colors(t_cube *cube);

void	content_validations(t_cube *cube, char *file)
{
	copy_file(cube, file);
	get_textures(cube);
	get_colors(cube);
	if (!check_textures(cube) && !check_colors(cube))
		ft_exit(WRONG_CONTENT);
	get_map(cube);
}

static void	copy_file(t_cube *cube, char *file)
{
	char	*line;
	int		lines;
	int		fd;
	int		i;

	lines = count_lines(file);
	cube->content.total_lines = lines;
	cube->content.content = malloc(sizeof(char*) * (lines + 1));
	fd = open_file(file);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		cube->content.content[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	cube->content.content[i] = NULL;
}

static int	count_lines(char *file)
{
	char	*line;
	int		count;
	int		fd;
	
	fd = open_file(file);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		ft_exit(WRONG_FILE);
	return (fd);
}

static int	check_textures(t_cube *cube)
{
	if (cube->content.north_pattern != NULL
		&& cube->content.south_pattern != NULL
		&& cube->content.west_pattern != NULL
		&& cube->content.east_pattern != NULL)
		return (1);
	return (0);
}

static int	check_colors(t_cube *cube)
{
	if (cube->content.floor_color != NULL
		&& cube->content.ceil_color != NULL)
		return (1);
	return (0);
}

// static void	check_content(cube, line)
// {
	
// }

// static void	textures(t_cube *cube, char *line)
// {
// 	char	**orientation_arr;
	
// 	if (ft_strlen(line) > 4)
// 	{
// 		orientation_arr = ft_split(line, ' ');
// 		if (!strict_strcmp(orientation_arr[0], NO))
// 			cube->north_pattern = ft_strdup(orientation_arr[1]);
// 		else if (!strict_strcmp(orientation_arr[0], SO))
// 			cube->south_pattern = ft_strdup(orientation_arr[1]);
// 		else if (!strict_strcmp(orientation_arr[0], WE))
// 			cube->west_pattern = ft_strdup(orientation_arr[1]);
// 		else if (!strict_strcmp(orientation_arr[0], EA))
// 			cube->east_pattern = ft_strdup(orientation_arr[1]);		
// 	}
// }


// NO ./path_to_the_north_texture\n

// NO
// ./path_to_the_north_texture\n
// \0


// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
