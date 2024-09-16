/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:59 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/04 15:58:33 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(int pix, int piy, t_fractal *fractal, int iterations)
{
	char	*addr;
	int		offset;
	int		color;

	if (ft_strncmp(fractal->color_set, "greyscale", 9) == 0)
		color = greyscale(iterations);
	else if (ft_strncmp(fractal->color_set, "rainbow", 7) == 0)
		color = rainbow(iterations);
	else if (ft_strncmp(fractal->color_set, "heatmap", 7) == 0)
		color = heatmap(iterations);
	else if (ft_strncmp(fractal->color_set, "psychadelic", 11) == 0)
		color = psychadelic(iterations);
	else
		color = 0;
	addr = fractal->img.addr;
	offset = piy * fractal->img.line_len + pix * (fractal->img.bpp / 8);
	addr[offset] = color & 0xFF;
	addr[offset + 1] = (color >> 8) & 0xFF;
	addr[offset + 2] = (color >> 16) & 0xFF;
}

void	handle_pixel(t_fractal *fractal, int pix, int piy)
{
	int			color;

	if (ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
		color = mandelbrot(fractal, pix, piy);
	else if (ft_strncmp(fractal->name, "julia", 5) == 0)
		color = julia(fractal, pix, piy);
	else
		return ;
	put_pixel(pix, piy, fractal, color);
}

void	render_fractol(t_fractal *fractal)
{
	int	x;
	int	y;

	mlx_clear_window(fractal->mlx, fractal->mlx_win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
