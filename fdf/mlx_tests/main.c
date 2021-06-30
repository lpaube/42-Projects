#include "../mlx_mac/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double	angle = 0.5;

double		projection[3][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 0}
};

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_point		points[4];
}				t_fdf;

t_point	init_point(int x, int y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_fdf	*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 800, 800, "CUB3D");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 800, 800);
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian);
	fdf->points[0] = init_point(300, 300, 0, 0x00FF0000);
	fdf->points[1] = init_point(500, 300, 0, 0x0000FF00);
	fdf->points[2] = init_point(300, 500, 0, 0x000000FF);
	fdf->points[3] = init_point(500, 500, 0, 0x00FFFF00);
	return (fdf);
}

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pxl_pos;

	pxl_pos = (y * fdf->size_line) + (x * (fdf->bits_per_pixel / 8));

	if (fdf->endian == 1)
	{
		fdf->addr[pxl_pos + 0] = (color >> 24);
		fdf->addr[pxl_pos + 1] = (color >> 16) & 0xFF;
		fdf->addr[pxl_pos + 2] = (color >> 8) & 0xFF;
		fdf->addr[pxl_pos + 3] = (color) & 0xFF;
	}
	else if (fdf->endian == 0)
	{
		fdf->addr[pxl_pos + 0] = (color) & 0xFF;
		fdf->addr[pxl_pos + 1] = (color >> 8) & 0xFF;
		fdf->addr[pxl_pos + 2] = (color >> 16) & 0xFF;
		fdf->addr[pxl_pos + 3] = (color >> 24);
	}
}

void	matmult(t_point *point, double matrix[3][3])
{
	int	old_x;
	int	old_y;
	int	old_z;

	old_x = point->x;
	old_y = point->y;
	old_z = point->z;
	point->x = old_x * matrix[0][0] + old_y * matrix[1][0] + old_z * matrix[2][0];
	point->y = old_x * matrix[0][1] + old_y * matrix[1][1] + old_z * matrix[2][1];
	point->z = old_x * matrix[0][2] + old_y * matrix[1][2] + old_z * matrix[2][2];
}

void	ft_rotate_x(t_point *point)
{
	double		rotate_x[3][3] = {
		{1, 0, 0},
		{0, cos(angle), -sin(angle)},
		{0, sin(angle), cos(angle)}
	};
	matmult(point, rotate_x);
}

void	draw_control(t_fdf *fdf)
{
	for (int i = 0; i < 4; i++)
	{
		matmult(&(fdf->points[i]), projection);
		ft_put_pixel(fdf, (fdf->points[i]).x, (fdf->points[i]).y, (fdf->points[i]).color);
	}
}

int	rotating(int keycode, t_fdf *fdf)
{
	printf("keycode: %d\n", keycode);
	for (int i = 0; i < 4; i++)
	{
		ft_rotate_x(&(fdf->points[i]));
		printf("i: %d | x: %d | y: %d\n", i, (fdf->points[i]).x, (fdf->points[i]).y);
	}
	return (0);
}

int	main(void)
{
	t_fdf	*fdf;

	fdf = fdf_init();
	draw_control(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_key_hook(fdf->win_ptr, rotating, fdf);
	printf("point0x: %d | point 3x: %d\n", (fdf->points)->x, ((fdf->points) + 3)->x);
	mlx_loop(fdf->mlx_ptr);
}
