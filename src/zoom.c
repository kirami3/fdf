/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsenal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:19:58 by harsenal          #+#    #+#             */
/*   Updated: 2021/10/06 22:20:00 by harsenal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

void	zoom_count(t_fdf *databox)
{
	int	i;
	int	i2;

	i2 = 900;
	databox->zoom = 1;
	i = databox->width;
	while (i > SIZE_X || databox->height > SIZE_Y)
	{
		databox->zoom /= 2;
	}
	databox->zoom = i2 / maximum(maximum(databox->top - databox->depth, \
		databox->width), databox->height);
	while (databox->zoom * databox->width > SIZE_X
		|| databox->zoom * databox->height > SIZE_Y
		|| databox->top * databox->zoom > SIZE_Y)
		databox->zoom /= 1.5;
}

void	find_depth(t_fdf *databox)
{
	int	i;
	int	i2;
	int	t;

	i = 0;
	t = 2147483647;
	while (i < databox->height)
	{
		i2 = 0;
		while (i2 < databox->width)
		{
			t = minimum(databox->z_matrix[i][i2], t);
			i2++;
		}
		i++;
	}
	databox->depth = t;
}

void	find_top(t_fdf *databox)
{
	int	i;
	int	i2;
	int	t;

	i = 0;
	t = 0;
	while (i < databox->height)
	{
		i2 = 0;
		while (i2 < databox->width)
		{
			t = maximum((modul(databox->z_matrix[i][i2])), t);
			i2++;
		}
		i++;
	}
	databox->top = t;
}
