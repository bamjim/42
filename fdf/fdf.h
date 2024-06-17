#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define READ_BUFFERSIZE 50000
# define WINDOW_X 1920
# define WINDOW_Y 1080
# define COLOR_WHITE 0xFFFFFF
//key
# define KEY_PRESS		2
# define KEY_ESC		65307
# define KEY_A			97
# define KEY_D			100
# define KEY_Q			113
# define KEY_W			119
# define KEY_S			115
# define KEY_E			101
# define KEY_R			114
typedef struct s_param
{
	void *mlx_ptr;
	void *win;
	int width;
	int height;

} t_param;

typedef struct s_pos
{
	int x;
	int y;
	int z;
	int	color;
}		t_pos;

typedef struct s_map
{
	t_pos *pos;
	t_pos *copy_pos;
	int	width;
	int	heigth;
	int	map_size;
	int	max_z;
	int	min_z;
	int	x_angle;
	int	y_angle;
	int	flag;
}		t_map;

typedef struct s_data
{
	t_map	*map;
	t_param	param;
	void		*img;
	char		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	scale;
}		t_data;


typedef struct s_ham
{
	int width;
	int height;
	int yfactor;
	int xfactor;
	int y;
	int x;
	int det;
	int det2;
}	t_ham;

//bresenham algorithm
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	hamham(t_ham *ham, t_pos *start, t_pos *end);
void bresenham(t_pos *start, t_pos *end, t_data *data);
//map_read.c
char	*map_set(char *dir);
char *map_read(int fd, char *buffer);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
//scale
void	pos_scale(t_map *map);
void	set_z_scale(t_map *map, t_data *data);
void	scale(t_map *map, t_data *data);
//map_load.c
void map_load(t_map *map, char *dir, t_data *data);
void	check_map_size(char *content, t_map *map);
void	init_xyz(t_map *map, int i, t_data *data);
//map_load_utils.c
int	check_content_value(char **nptr, t_pos *pos);
//utils.c
int	ft_isalpha(int c);
int fdf_is_space(char s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_isdigit(char c);
void	fdf_error(char * msg);
//isometric
void isometric(t_map *map);
//draw.c
void	copy_draw(t_map *map,t_data *data);
void	draw(t_map *map,t_data *data);
void	resize_draw(t_map *map, t_data *data);
//draw_utils.c
void	init_copy_pos(t_map *map);
void	*ft_memset(void *s, int c, size_t n);
void draw_line(t_map *map, t_data *data);
void draw_copy_line(t_map *map, t_data *data);
//color.c
void	get_color(t_pos *pos, char **content);
//key
int	key_press(int keycode, t_data *data);

#endif