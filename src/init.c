/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stonegaw <stonegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:54:12 by stonegaw          #+#    #+#             */
/*   Updated: 2025/12/23 20:54:14 by stonegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	data_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->addr = NULL;
	data->min_r = -2.0;
	data->max_r = 1.0;
	data->min_i = -1.5;
	data->max_i = 1.5;
	data->is_mousedown = 0;
	data->mouse_last_x = 0;
	data->mouse_last_y = 0;
	data->cr = 0.0;
	data->ci = 0.0;
	data->julia_cx = 0.0;
	data->julia_cy = 0.0;
	data->fractal_type = -1;
}

void	*init(void)
{
	void	*res;

	res = mlx_init();
	if (!res)
	{
		perror("mlx_init failed");
		exit(EXIT_FAILURE);
	}
	return (res);
}

void	*new_window(t_data *data)
{
	void	*res;
	char	*title;

	title = NULL;
	if (data->fractal_type == MANDELBROT)
		title = "Mandelbrot";
	else if (data->fractal_type == JULIA)
		title = "Julia";
	res = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
	if (!res)
	{
		perror("mlx_new_window failed");
		exit(EXIT_FAILURE);
	}
	return (res);
}

char	*new_image(t_data *data)
{
	void	*res;

	data->img_ptr = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img_ptr)
	{
		perror("mlx_new_image failed");
		exit(EXIT_FAILURE);
	}
	res = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!res)
	{
		perror("mlx_get_data_addr failed");
		exit(EXIT_FAILURE);
	}
	return (res);
}
