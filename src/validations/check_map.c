/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:45:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/27 01:23:01 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_first_row(t_cube *cube);
static int	check_last_row(t_cube *cube);
static int	check_valid_chars(unsigned int i, char *s);

int	check_map(t_cube *cube)
{
	if (check_first_row(cube) 
		&& check_body(cube)
		&& check_last_row(cube))
		return (1);
	return (0);
}

static int	check_first_row(t_cube *cube)
{
	if (!ft_striteri_check(cube->map.map[0], check_valid_chars))
		return (0);
	return (1);
}

static int	check_last_row(t_cube *cube)
{
	int	i;

	i = cube->content.total_lines;
	while (ft_striteri_check(cube->map.map[i], ft_is_space))
		i--;
	if (!ft_striteri_check(cube->map.map[i], check_valid_chars))
		return (0);
	return (1);
}

static int	check_valid_chars(unsigned int i, char *s)
{
	if (ft_is_space(i, s) || s[i] == '1')
		return (1);
	return (0);
}

static int	check_body(t_cube *cube)
{
	int		len;
	int		i;
	int		j;
	char	*string_dup;
	char	*string_trimmed;

	i = 1;
	while (cube->map.map[i])
	{
		string_dup = ft_strdup(cube->map.map[i]);
		string_trimmed = ft_strtrim(string_dup, ' ');
		free(string_dup);
		string_dup = ft_strdup(string_trimmed);
		free(string_trimmed);
		string_trimmed = ft_strtrim(string_dup, '\t');
		len = ft_strlen(cube->map.map[i]);
		
		i++;
	}
}


