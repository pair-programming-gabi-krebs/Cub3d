/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:45:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/30 02:54:00 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static int	check_first_row(t_cube *cube);
static int	check_last_row(t_cube *cube);
static int	check_valid_chars(char *s);
static int	map_last_line(t_cube *cube);
static int	check_body(t_cube *cube);


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
	if (!check_valid_chars(cube->map.map[0]))
	{
		printf("parei no first row\n");
		return (0);
	}
	return (1);
}

static int	check_last_row(t_cube *cube)
{
	if (!check_valid_chars(cube->map.map[map_last_line(cube)]))
	{
		printf("parei no last row\n");
		return (0);
	}
	return (1);
}

static int	check_valid_chars(char *s)
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

// static int	check_body(t_cube *cube)
// {
// 	int		len;
// 	int		i;
// 	//int		j;
// 	char	*string_dup;
// 	char	*string_trimmed;

// 	i = 1;
// 	while (cube->map.map[i])
// 	{
// 		string_dup = ft_strdup(cube->map.map[i]);
// 		string_trimmed = ft_strtrim(string_dup, " ");
// 		free(string_dup);
// 		string_dup = ft_strdup(string_trimmed);
// 		free(string_trimmed);
// 		string_trimmed = ft_strtrim(string_dup, "\t");
// 		free(string_dup);
// 		string_dup = ft_strdup(string_trimmed);
// 		free(string_trimmed);
// 		string_trimmed = ft_strtrim(string_dup, "\r");
// 		free(string_dup);
// 		string_dup = ft_strdup(string_trimmed);
// 		free(string_trimmed);
// 		string_trimmed = ft_strtrim(string_dup, "\n");
// 		free(string_dup);
// 		string_dup = ft_strdup(string_trimmed);
// 		free(string_trimmed);
// 		len = ft_strlen(string_dup);
// 		if (string_dup[0] != '1' && string_dup[len - 1] != '1')
// 		{
// 			printf("parei no body row: %d\n", i);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }


