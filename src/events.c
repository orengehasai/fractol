/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stonegaw <stonegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:53:44 by stonegaw          #+#    #+#             */
/*   Updated: 2025/12/23 20:53:46 by stonegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_release(int buttoncode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (buttoncode == 1)
	{
		data->is_mousedown = 0;
	}
	return (0);
}

int	mouse_press(int buttoncode, int x, int y, t_data *data)
{
	if (buttoncode == MOUSE_UP || buttoncode == MOUSE_DOWN)
	{
		zoom(buttoncode, data);
	}
	else if (buttoncode == 1)
	{
		data->is_mousedown = 1;
		data->mouse_last_x = x;
		data->mouse_last_y = y;
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int		dx;
	int		dy;
	double	range_r;
	double	range_i;

	if (data->is_mousedown == 0)
		return (0);
	dx = x - data->mouse_last_x;
	dy = y - data->mouse_last_y;
	range_r = data->max_r - data->min_r;
	range_i = data->max_i - data->min_i;
	data->min_r -= dx * (range_r / WIN_WIDTH);
	data->max_r -= dx * (range_r / WIN_WIDTH);
	data->min_i += dy * (range_i / WIN_HEIGHT);
	data->max_i += dy * (range_i / WIN_HEIGHT);
	render(data);
	data->mouse_last_x = x;
	data->mouse_last_y = y;
	return (0);
}

void	zoom(int buttoncode, t_data *data)
{
	double	zoom_factor;
	double	range_r;
	double	range_i;
	double	center_r;
	double	center_i;

	range_r = data->max_r - data->min_r;
	range_i = data->max_i - data->min_i;
	center_r = (data->min_r + data->max_r) / 2.0;
	center_i = (data->min_i + data->max_i) / 2.0;
	if (buttoncode == MOUSE_UP)
		zoom_factor = 0.9;
	else if (buttoncode == MOUSE_DOWN)
		zoom_factor = 1.1;
	else
		return ;
	data->min_r = center_r - (range_r * zoom_factor) / 2.0;
	data->max_r = center_r + (range_r * zoom_factor) / 2.0;
	data->min_i = center_i - (range_i * zoom_factor) / 2.0;
	data->max_i = center_i + (range_i * zoom_factor) / 2.0;
	render(data);
}
