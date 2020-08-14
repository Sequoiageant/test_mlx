/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:55:10 by julnolle          #+#    #+#             */
/*   Updated: 2020/08/14 14:38:50 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_mlx.h"

void		ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	free(mlx->mlx_ptr);
	exit(SUCCESS);
}

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	print_square(t_mlx *mlx)
{
	int y;
	int x;
	int color;

	color = rgb_to_int(119, 206, 36);
	x = 0;
	while(x < 300)
	{
		y = 0;
		while (y < 300)
		{
			ft_pixel_put(mlx, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img, 0, 0);
}

int	key_event(int key, t_mlx *mlx)
{
	if (key == ESC)
		ft_close(mlx);
	if (key == KEY_S)
		print_square(mlx);
	return (0);
}

int	test_mlx(void)
{
	t_mlx	mlx;
	t_win	win;

	win.h = 600;
	win.w = 600;
	if ((mlx.mlx_ptr = mlx_init()) == NULL)
		return (FAILURE);
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, win.w, win.h, "Test MLX");
	if (mlx.mlx_win == NULL)
		return (FAILURE);
	if ((mlx.img = mlx_new_image(mlx.mlx_ptr, win.w, win.h)) == NULL)
		return (FAILURE);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.line_len, &mlx.end);
	if (mlx.addr == NULL)
		return (FAILURE);
	mlx_hook(mlx.mlx_win, 3, (1 << 1), key_event, &mlx);
	mlx_hook(mlx.mlx_win, 17, (1L << 17), ft_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (SUCCESS);
}

int main(void)
{
	if (test_mlx() == FAILURE)
		ft_putendl("Erreur MLX");
	return (0);
}
