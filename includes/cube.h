/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:54:44 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/16 23:49:17 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libraries/libft.h"

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
} t_cube;

void	ft_exit(char *message);
int		strict_strcmp(const char *s1, const char *s2);

// Validations
void	file_validations(t_cube *cube, char *file);
void	content_validations(t_cube *cube, int fd);

#endif