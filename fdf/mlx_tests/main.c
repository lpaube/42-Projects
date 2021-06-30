#include "../mlx_mac/mlx.h"
#include <stdlib.h>
#include <stdio.h>

double	angle = 0.01;

int		projection[3][3] = {
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
}				t_fdf;

t_fdf	*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 800, 800, "CUB3D");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 800, 800);
	fdf->addr = mlx_get_data_addr(fdf->img_ptr, &fdf->bits_per_pixel, &fdf->size_line, &fdf->endian);
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

t_point	init_point(int x, int y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

void	matmult(t_point *point, int	matrix[3][3])
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

void	draw_control(t_fdf *fdf)
{
	t_point point_arr[4];

	point_arr[0] = (init_point(300, 300, 0, 0x00FF0000));
	point_arr[1] = (init_point(500, 300, 0, 0x0000FF00));
	point_arr[2] = (init_point(300, 500, 0, 0x000000FF));
	point_arr[3] = (init_point(500, 500, 0, 0x00FFFF00));

	for (int i = 0; i < 4; i++)
	{
		matmult(&(point_arr[i]), projection);
		ft_put_pixel(fdf, point_arr[i].x, point_arr[i].y, point_arr[i].color);
	}
}

int	main(void)
{
	t_fdf	*fdf;

	fdf = fdf_init();
	draw_control(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_loop(fdf->mlx_ptr);
}
