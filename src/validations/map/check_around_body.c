/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_body.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:06:49 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:07:08 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

int	check_around_body(t_cube *cube)
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
