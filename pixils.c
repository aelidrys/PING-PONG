/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelidrys <aelidrys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:09:55 by aelidrys          #+#    #+#             */
/*   Updated: 2023/07/25 10:51:19 by aelidrys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_game.h"

void	my_mlx_pixel_put1(t_imge *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= 640 || y < 0 || y >= 640)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_put(t_game *game, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= 640 || y < 0 || y >= 640)
		return ;
	dst = game->img->addr + (y * game->img->line_length + x * (game->img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
