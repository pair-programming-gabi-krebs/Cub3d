/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:35:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/09/29 03:47:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

int	ft_striteri_check(char *s, int (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		printf("s[%d]: %d\n", i, s[i]);
		if (s[i] != 32 && !(s[i] >= 9 && s[i] <= 13) && s[i] != 49)
		{
			return (0);
		}
		if (!f(i, &s[i]))
			printf("hoi\n");
		i++;
	}
	return (1);
}