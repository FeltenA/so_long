/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:23:43 by afelten           #+#    #+#             */
/*   Updated: 2022/06/08 15:34:43 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
int	close(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img.img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	printf("%d\n", keycode);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 900, 800, "so long");
	data.img.img = mlx_new_image(data.mlx, 900, 800);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp,
										&data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_key_hook(data.win, close, &data);
	mlx_loop(data.mlx);
}
