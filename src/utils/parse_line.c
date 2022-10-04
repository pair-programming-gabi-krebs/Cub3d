/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:08:23 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/05 02:08:52 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	parse_line(char **str, char *arg)
{
	char	*string_trimmed;

	string_trimmed = ft_strtrim(*str, arg);
	free(*str);
	*str = ft_strdup(string_trimmed);
	free(string_trimmed);
}
