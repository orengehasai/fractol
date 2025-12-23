/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stonegaw <stonegaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:51:05 by takenakatak       #+#    #+#             */
/*   Updated: 2025/12/14 19:12:14 by stonegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define STDERR 2
# define R_FACTOR 1
# define G_FACTOR 2
# define B_FACTOR 5
# define MANDELBROT 0
# define JULIA 1
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define MOUSE_LEFT_CLICK 1
# define KEY_PRESS_EVENT 2
# define MOUSE_PRESS_EVENT 4
# define DESTROY_NOTIFY_EVENT 17
# define MOUSE_RELEASE_EVENT 5
# define POINTER_MOTION_EVENT 6
# define KEY_PRESS_MASK 1
# define MOUSE_PRESS_MASK 4
# define DESTROY_NOTIFY_MASK 131072
# define MOUSE_RELEASE_MASK 8
# define POINTER_MOTION_MASK 64
# ifdef __linux__
#  define KEY_ESC 65307
# else
#  define KEY_ESC 53
# endif
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MAX_ITER 100

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		is_mousedown;
	int		mouse_last_x;
	int		mouse_last_y;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	cr;
	double	ci;
	double	julia_cx;
	double	julia_cy;
	int		fractal_type;
}	t_data;

double	ft_atof(char *str);

void	ft_putstr_fd(char *s, int fd);

int		is_double(const char *str);

int		ft_strcmp(char *s1, char *s2);

void	data_init(t_data *data);

void	*init(void);

void	*new_window(t_data *data);

char	*new_image(t_data *data);

int		mandelbrot(t_data *data);

int		julia(t_data *data);

void	render(t_data *data);

int		close_window(t_data *data);

int		key_press(int keycode, t_data *data);

int		mouse_press(int buttoncode, int x, int y, t_data *data);

int		mouse_release(int button, int x, int y, t_data *data);

int		mouse_move(int x, int y, t_data *data);

void	zoom(int button, t_data *data);

#endif