/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:45:31 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/11/17 21:01:51 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	render(t_cube *cube)
{
	// verificar se o player atualizou, se não, não renderizar nada
	update_player(cube);
	render_player(cube);
	render_map(cube);
	return (0);
}
