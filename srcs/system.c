#include "system.h"

void	system_exit(t_sys *sys, int status)
{
	if (status == E_INVALID_INPUT)
	{
		// ft_putstr_fd(ERRMSG1, 2);
		// ft_putstr_fd(ERRMSG2, 2);
	}
	free(sys);
	exit(status);
}

t_sys	*system_init(char *arg)
{
	t_sys *sys;

	sys = ft_calloc(1, sizeof(t_sys));
	if (!sys)
		system_exit(NULL, E_ALLOCATE);
	// sys->type = identify_arg(arg, sys);
	// sys->col = 0x080808;
	// sys->screen.base.im = -4;
	// sys->screen.base.re = -4;
	// sys->screen.height = 8;
	// sys->screen.width = 8;
	sys->mlx = mlx_init();
	if (!sys->mlx)
		system_exit(NULL, E_MLX_INIT);
	sys->win = mlx_new_window(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "FRACTOL");
	if (!sys->win)
		system_exit(NULL, E_MLX_INIT);
	sys->img.img = mlx_new_image(sys->mlx, SCREEN_HEIGHT, SCREEN_WIDTH);
	if (!sys->img.img)
		system_exit(NULL, E_ALLOCATE);
	sys->img.addr = mlx_get_data_addr(sys->img.img, &sys->img.bits_per_pixel,
			&sys->img.line_length, &sys->img.endian);
	return (sys);
}