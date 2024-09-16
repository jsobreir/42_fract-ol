/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:31:00 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/08 11:56:23 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_picker(t_fractal *fractal)
{

	if (ft_strncmp(fractal->color_set, "greyscale", 9) == 0)
	{
		fractal->color_set = "rainbow";
		ft_printf("Energy color palette set.\n");
	}
	else if (ft_strncmp(fractal->color_set, "rainbow", 7) == 0)
	{
		fractal->color_set = "heatmap";
		ft_printf("Bloody color palette set.\n");
	}
	else if (ft_strncmp(fractal->color_set, "heatmap", 7) == 0)
	{
		fractal->color_set = "psychadelic";
		ft_printf("Gold color palette set.\n");
	}
	else if (ft_strncmp(fractal->color_set, "psychadelic", 11) == 0)
	{
		fractal->color_set = "greyscale";
		ft_printf("Grey color palette set.\n");
	}
}

int	greyscale(int n)
{
	int	r;
	int	g;
	int	b;

	if (n == MAX_ITERATIONS)
		return (0);
	r = (int)((double)n * 255 / (double)MAX_ITERATIONS);
	g = r;
	b = r;
	return (r << 16 | g << 8 | b);
}

int	rainbow(int n)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (n == MAX_ITERATIONS)
		return (0);
	t = (double)n / (double)MAX_ITERATIONS;
	r = (int)(2 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(4 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

int	heatmap(int n)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)n / (double)MAX_ITERATIONS;
	r = (int)(0.9 * t * 255);
	g = (int)(0.25 * t * 255);
	b = (int)(0.2 * t * 255);
	return (r << 16 | g << 8 | b);
}

int	psychadelic(int n)
{
	int	r;
	int	g;
	int	b;

	if (n == MAX_ITERATIONS)
		return (0);
	r = (int)((double)n * 7) % 256;
	g = (int)((double)n * 5) % 256;
	b = (int)((double)n * 3) % 256;
	return (r << 16 | g << 8 | b);
}
