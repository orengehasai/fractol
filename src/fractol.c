/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stonegaw <stonegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:54:07 by stonegaw          #+#    #+#             */
/*   Updated: 2025/12/23 20:54:09 by stonegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_data *data)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		temp = zr * zr - zi * zi + data->cr;
		zi = 2.0 * zr * zi + data->ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_data *data)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = data->cr;
	zi = data->ci;
	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		temp = zr * zr - zi * zi + data->julia_cx;
		zi = 2.0 * zr * zi + data->julia_cy;
		zr = temp;
		iter++;
	}
	return (iter);
}
