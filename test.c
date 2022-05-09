int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	x, y;

	mlx_ptr = mlx_init();
	//void *image = mlx_new_image(mlx_ptr, x, y);
	void	*img = mlx_xpm_file_to_image(mlx_ptr, "./Texture/box.xpm", &x, &y);
	void	*img2 = mlx_xpm_file_to_image(mlx_ptr, "./Texture/tile.xpm", &x, &y);
	win_ptr = mlx_new_window(mlx_ptr, 128, 128, "title");
	mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 0, 0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img2, 32, 0);
	mlx_loop(mlx_ptr);
	return (0);
}