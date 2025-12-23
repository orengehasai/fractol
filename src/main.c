/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stonegaw <stonegaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:54:16 by stonegaw          #+#    #+#             */
/*   Updated: 2025/12/23 20:54:18 by stonegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage_and_exit(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", STDERR_FILENO);
	ft_putstr_fd("Usage: ./fractol <fractal_name> [params]\n", STDERR_FILENO);
	ft_putstr_fd("\nAvailable fractals:\n", STDERR_FILENO);
	ft_putstr_fd("  - mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("  - julia <real> <imag>\n", STDERR_FILENO);
	ft_putstr_fd("\nExamples:\n", STDERR_FILENO);
	ft_putstr_fd("  ./fractol mandelbrot\n", STDERR_FILENO);
	ft_putstr_fd("  ./fractol julia -0.8 0.156\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	validate_args(int ac, char **av, t_data *data)
{
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
	{
		data->fractal_type = MANDELBROT;
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia") && is_double(av[2])
		&& is_double(av[3]))
	{
		data->fractal_type = JULIA;
		data->julia_cx = ft_atof(av[2]);
		data->julia_cy = ft_atof(av[3]);
	}
	else
	{
		print_usage_and_exit();
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data_init(&data);
	validate_args(ac, av, &data);
	data.mlx_ptr = init();
	data.win_ptr = new_window(&data);
	data.addr = new_image(&data);
	mlx_hook(data.win_ptr, KEY_PRESS_EVENT, KEY_PRESS_MASK, key_press, &data);
	mlx_hook(data.win_ptr, MOUSE_PRESS_EVENT, MOUSE_PRESS_MASK, mouse_press,
		&data);
	mlx_hook(data.win_ptr, DESTROY_NOTIFY_EVENT, DESTROY_NOTIFY_MASK,
		close_window, &data);
	mlx_hook(data.win_ptr, MOUSE_RELEASE_EVENT, MOUSE_RELEASE_MASK,
		mouse_release, &data);
	mlx_hook(data.win_ptr, POINTER_MOTION_EVENT, POINTER_MOTION_MASK,
		mouse_move, &data);
	render(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
