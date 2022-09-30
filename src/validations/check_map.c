/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:45:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/30 04:53:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_first_row(t_cube *cube);
static int	check_last_row(t_cube *cube);
static int	check_valid_chars_line(char *s);
static int	map_last_line(t_cube *cube);
static int	check_around_body(t_cube *cube);
static void	parse_line(char **str, char *arg);
static int	check_around_spaces(t_cube *cube);
static int	check_space(t_cube *cube, int i, int j);


int	check_map(t_cube *cube)
{
	if (check_first_row(cube) 
		&& check_last_row(cube)
		&& check_around_body(cube)
		&& check_around_spaces(cube))
		return (1);
	return (0);
}

static int	check_first_row(t_cube *cube)
{
	if (!check_valid_chars_line(cube->map.map[0]))
	{
		printf("parei no first row\n");
		return (0);
	}
	return (1);
}

static int	check_last_row(t_cube *cube)
{
	if (!check_valid_chars_line(cube->map.map[map_last_line(cube)]))
	{
		printf("parei no last row\n");
		return (0);
	}
	return (1);
}

static int	check_valid_chars_line(char *s)
{
	int	i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != 49)
			return (0);
		i++;
	}
	return (1);
}

static int	map_last_line(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->map.map[i])
		i++;
	return (i - 1);
}

static int	check_around_body(t_cube *cube)
{
	int		len;
	int		i;

	char	*string_dup;

	i = 1;
	while (cube->map.map[i])
	{
		string_dup = ft_strdup(cube->map.map[i]);
		parse_line(&string_dup, " ");
		parse_line(&string_dup, "\t");
		parse_line(&string_dup, "\r");
		parse_line(&string_dup, "\n");
		len = ft_strlen(string_dup);
		printf("%s\n", string_dup);
		if ((string_dup[0] && string_dup[len - 1]) && (string_dup[0] != '1' || \
			string_dup[len - 1] != '1'))
		{
			printf("parei no body row: %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

static int check_around_spaces(t_cube *cube)
{
	int		i;
	int		j;
	

	i = 0;
	while (cube->map.map[i])
	{
		j = 0;
		while (cube->map.map[i][j])
		{
			if (!check_space(cube, i , j))
			{
				printf("ok n\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_valid_chars(char chr)
{
	if (chr != 32 && !(chr >= 9 && chr <= 13) && chr != 49)
		return (0);
	return (1);
}

static int	check_space(t_cube *cube, int i, int j)
{
	if (cube->map.map[i][j] && check_valid_chars(cube->map.map[i][j]))
	{
		if ((cube->map.map[i - 1] && check_valid_chars(cube->map.map[i - 1][j]))
			&& (cube->map.map[i + 1] && check_valid_chars(cube->map.map[i + 1][j]))
			&& (cube->map.map[i] && check_valid_chars(cube->map.map[i][j - 1]))
			&& (cube->map.map[i] && check_valid_chars(cube->map.map[i][j + 1])))
			return (1);
	}
	return (0);
}

static void	parse_line(char **str, char *arg)
{
	char	*string_trimmed;

	string_trimmed = ft_strtrim(*str, arg);
	free(*str);
	*str = ft_strdup(string_trimmed);
	free(string_trimmed);
}
