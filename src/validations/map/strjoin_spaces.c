/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:57:55 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/14 04:58:28 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cube.h"

void	strjoin_spaces(char **map, size_t big_str, size_t len, int i)
{
	char	*spaces;
	char	*aux;
	int		diff;

	diff = big_str - len;
	spaces = malloc(sizeof(char) * (diff));
	ft_memset(spaces, ' ', diff);
	spaces[diff - 1] = '\0';
	map[i][len - 1] = ' ';
	aux = ft_strdup(map[i]);
	free(map[i]);
	map[i] = ft_strjoin(aux, spaces);
	free(aux);
	free(spaces);
}
