/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:13:41 by jsobreir         #+#    #+#             */
/*   Updated: 2024/06/18 14:33:05 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	on_key_press(int keycode, t_fractal *fractal)
{
	if (keycode == K_J)
		fractal->j_pressed = 1;
	else if (keycode == K_K)
		fractal->k_pressed = 1;
	key_hooks(keycode, fractal);
	return (0);
}

static int	on_key_release(int keycode, t_fractal *fractal)
{
	if (keycode == K_J)
		fractal->j_pressed = 0;
	else if (keycode == K_K)
		fractal->k_pressed = 0;
	return (0);
}

static void	setup_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, (1L << 0), on_key_press, fractal);
	mlx_hook(fractal->mlx_win, KeyRelease, (1L << 1), on_key_release, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, (1L << 2), mouse_hooks, fractal);
	mlx_hook(fractal->mlx_win, 17, 0, clean_exit, fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	fractal_init(&fractal);
	if (argc < 2)
		wrong_format(&fractal);
	fractal.name = argv[1];
	if (!fractal.name)
		wrong_format(&fractal);
	if (ft_strncmp(fractal.name, "mandelbrot", 10) != 0
		&& ft_strncmp(fractal.name, "julia", 5) != 0)
		wrong_format(&fractal);
	init_fractal_dimensions(&fractal, argv, argc);
	render_fractol(&fractal);
	setup_hooks(&fractal);
	mlx_loop_hook(fractal.mlx, fluid_hooks, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
