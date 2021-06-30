#include "../mlx_mac/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double	angle = 0.5;

double		projection[3][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
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
	fdf->points[0] = init_point(300, 300, 0, 0x00FF00FF);
	fdf->points[1] = init_point(500, 300, 0, 0x0000FF00);
	fdf->points[2] = init_point(300, 500, 0, 0x0000FFFF);
	fdf->points[3] = init_point(500, 500, 0, 0x00FFFF00);
	return (fdf);
}

void	ft_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	pxl_pos;

	pxl_pos = (y * fdf->size_line) + (x * (fdf->bits_per_pixel / 8));

	if (x < 0 || y < 0 || x > 800 || y > 800)
		return ;
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
	double	old_x;
	double	old_y;
	double	old_z;
	int mid = 400;

	old_x = point->x - mid;
	old_y = point->y - mid;
	printf("old_y pre: %f\n", old_y);
	old_z = point->z;
	point->x = round(old_x * matrix[0][0] + old_y * matrix[1][0] + old_z * matrix[2][0] + mid);
	point->y = round(old_x * matrix[0][1] + old_y * matrix[1][1] + old_z * matrix[2][1] + mid);
	printf("point->y post: %d | old_x: %f | old_y: %f | old_z: %f | mat[0][1]: %f | mat[1][1]: %f\n", point->y, old_x, old_y, old_z, matrix[0][1], matrix[1][1]);
	//this is off :(
	point->z = round(old_x * matrix[0][2] + old_y * matrix[1][2] + old_z * matrix[2][2]);
}

void	ft_rotate_x(t_point *point)
{
	double		rotate_x[3][3] = {
		{1, 0, 0},
		{0, cos(angle), -sin(angle)},
		{0, sin(angle), cos(angle)}
	};
	printf("ROTATE_X\n");
	matmult(point, rotate_x);
}

void	ft_rotate_z(t_point *point)
{
	double		rotate_z[3][3] = {
		{cos(angle), -sin(angle), 0},
		{sin(angle), cos(angle), 0},
		{0, 0, 1}
	};
	printf("ROTATE_X\n");
	matmult(point, rotate_z);
}

void	draw_control(t_fdf *fdf)
{
	for (int i = 0; i < 4; i++)
	{
		printf("PROJECTION\n");
		matmult(&(fdf->points[i]), projection);
		ft_put_pixel(fdf, (fdf->points[i]).x, (fdf->points[i]).y, (fdf->points[i]).color);
	}
	printf("\n");
}

void	clear_image(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < (800 * 800 * 4))
	{
		fdf->addr[i] = 0;
		i++;
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
	printf("--- ---\n");
	clear_image(fdf);
	draw_control(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	return (0);
}

int	main(void)
{
	t_fdf	*fdf;

	fdf = fdf_init();
	draw_control(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_key_hook(fdf->win_ptr, rotating, fdf);
	mlx_loop(fdf->mlx_ptr);
}
