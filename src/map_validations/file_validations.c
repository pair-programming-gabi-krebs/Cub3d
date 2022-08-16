/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 22:30:39 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/08/15 22:52:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void path_validation(char *file);

void    file_validations(char *file)
{
    if (file)
    {
        path_validation(file);
        
    }
}

static void path_validation(char *file)
{
        char    *dot;

        dot = ft_strchr(file, '.');
        if (!strict_cmp())
            ft_exit(WRONG_EXTENSIONS);
}