
#include "so_long.h"

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int event(int key_code)
{	
	printf("key -> %d\n", key_code);
	return 0;
}
void init_game(Game_state *state, Window_info *win_info)
{
	*state = LOADING;
}
check_game_files(Game_state *state)
{
	*state = START;
	
}
void play(void *mlx, Game_state *state)
{

}
Game_state loas_map(void *mlx, void *window)
{

}

int main()
{
	void		*mlx;
	void		*window;
	Game_state	game_state;
	Window_info win_info;

	init_game(&game_state, &win_info);
	check_game_files(&game_state);
	mlx = mlx_init();
	window = mlx_new_window(mlx, win_info.win_width, win_info.win_height, "~!~ prismo ~!~");
	if (game_state == START)
	{
		//load_map
		//draw assets
		game_state = PLAYING;
	}
	else if (game_state == LOADING)
	{
		game_state = load_map(mlx, window);
	}
	else if (game_state == PLAYING)
	{
		play(mlx, &game_state);
		//listen to move and gameplay config
		//if win or lose show replay or exit
		//if crash state => error
		//if exit pressed => exit
	}
	else if (game_state == REPLAY)
	{
		//clear the window and reset the score
		game_state = START;
	}
	else if (game_state == ERROR)
	{
		//desplay the error
		game_state = EXIT;
	}
	else if (game_state == EXIT)
	{
		mlx_destroy_window(mlx, window);
	}
	mlx_string_put(mlx, window, 400, 300, 0xffff0f00, "start");
	mlx_loop(mlx);
}
