/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:54:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/24 22:43:01 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libs/libft.h"

# define WRONG_FILE "Enter a valid map"
# define WRONG_EXTENSIONS "Enter a valid .cub file"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"

typedef struct s_cube
{
	char	*north_pattern;
	char	*south_pattern;
	char	*west_pattern;
	char	*east_pattern;
	void	*mlx_ptr;
	void	*mlx_win;
	
} t_cube;

// Validations
void	file_validations(t_cube *cube, int arguments, char *file);
void	content_validations(t_cube *cube, int fd);

void	init_window(t_cube *cube);

// Utils
void	ft_exit(char *message);
int		strict_strcmp(const char *s1, const char *s2);

#endif