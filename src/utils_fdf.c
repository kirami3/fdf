/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harsenal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:19:17 by harsenal          #+#    #+#             */
/*   Updated: 2021/10/06 22:19:18 by harsenal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_fdf.h"

int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	minimum(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	modul(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	start_param_set(t_fdf *db)
{
	db->angle = 0.523599;
	db->x_shift = 0;
	db->y_shift = 0;
	db->start_y_shift = 0;
	db->start_x_shift = 0;
}

void	mlx_start(t_fdf *db)
{
	db->mlx_ptr = mlx_init();
	db->win_ptr = mlx_new_window(db->mlx_ptr, SIZE_X, SIZE_Y, "fdf");
	db->img_ptr = mlx_new_image(db->mlx_ptr, SIZE_X, SIZE_Y);
	db->addr = mlx_get_data_addr(db->img_ptr, &db->bpp, \
				&db->l_l, &db->en);
}
