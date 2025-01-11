#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include "libc.h"
#include <errno.h>



typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef enum {
	LOADING, START , PLAYING , REPLAY, ERROR, EXIT 
} Game_state;

typedef struct {
	int win_width;
	int win_height;
} Window_info;
#endif