#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define READ_BUFFERSIZE 50000
# define WINDOW_X 1920
# define WINDOW_Y 1080
# define SCALE 1.5
# define COLOR_WHITE 0x00FFAA

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
	int	width;
	int	heigth;
	int	map_size;
	int	max_x;
	int	min_x;
	int	max_y;
	int	min_y;
}		t_map;

typedef struct s_data
{
	t_map	*map;
	void		*img;
	char		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
//map_load.c
void map_load(t_map *map, char *dir);
void	check_map_size(char *content, t_map *map);
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
void draw_line(t_map *map, t_data *data);
//color.c
void	get_color(t_pos *pos, char **content);
//scale
void	pos_scale(t_map *map);
#endif