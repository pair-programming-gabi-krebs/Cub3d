/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 05:12:39 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/10/10 22:26:44 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

void	parse_line(char **line)
{
	trim_line(line, " ");
	trim_line(line, "\t");
	trim_line(line, "\r");
	trim_line(line, "\n");
}
