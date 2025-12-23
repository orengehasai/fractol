/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takenakatakeshiichirouta <takenakatakes    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 20:04:51 by takenakatak       #+#    #+#             */
/*   Updated: 2025/11/29 20:17:01 by takenakatak      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	color_pallet(int iter)
{
	int	res;
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		res = 0x000000;
	else
	{
		r = (iter * R_FACTOR) % 256;
		g = (iter * G_FACTOR) % 256;
		b = (iter * B_FACTOR) % 256;
		res = (r << 16) | (g << 8) | b;
	}
	return (res);
}

static void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	calc_iter(t_data *data)
{
	int	iter;

	if (data->fractal_type == MANDELBROT)
		iter = mandelbrot(data);
	else
		iter = julia(data);
	return (iter);
}

void	render(t_data *data)
{
	int	y;
	int	x;
	int	iter;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		data->ci = data->max_i - (double)y * (data->max_i - data->min_i)
			/ WIN_HEIGHT;
		x = 0;
		while (x < WIN_WIDTH)
		{
			data->cr = data->min_r + (double)x * (data->max_r - data->min_r)
				/ WIN_WIDTH;
			iter = calc_iter(data);
			color = color_pallet(iter);
			pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
