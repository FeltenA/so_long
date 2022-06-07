/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:23:43 by afelten           #+#    #+#             */
/*   Updated: 2022/06/07 16:54:51 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 900, 800, "so long");
	data.img.img = mlx_new_image(data.mlx, 900, 800);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
										&data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_loop(data.mlx);
}
