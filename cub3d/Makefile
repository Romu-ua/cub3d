NAME		= cub3d
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_DIR		= /workspace/hyamamot/minilibx-linux
INCLUDES	= -I$(MLX_DIR) -Iinclude
LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCS_UTILS	= src/utils/ft_atoi.c \
			src/utils/ft_isdigit.c \
			src/utils/ft_isspace.c \
			src/utils/ft_memcpy.c \
			src/utils/ft_memmove.c \
			src/utils/ft_memset.c \
			src/utils/ft_realloc.c \
			src/utils/ft_split.c \
			src/utils/ft_strchr.c \
			src/utils/ft_strcpy.c \
			src/utils/ft_strdup.c \
			src/utils/ft_strjoin.c \
			src/utils/ft_strlen.c \
			src/utils/ft_strncmp.c \
			src/utils/ft_strlcpy.c \
			src/utils/ft_substr.c \
			src/utils/get_next_line.c

SRCS_INIT	= src/init/init.c \
			src/init/map_init.c \
			src/init/map_free.c \
			src/init/content_init.c

SRCS_RAY	= src/raycasting/get_move_input.c \
			src/raycasting/key_event.c \
			src/raycasting/raycasting.c \
			src/raycasting/render_fram.c \
			src/raycasting/render_util.c \
			src/raycasting/render.c

SRCS_VALID	= src/valid/valid.c \
			src/valid/dfs.c

SRCS		= $(SRCS_UTILS) $(SRCS_INIT) $(SRCS_RAY) $(SRCS_VALID) src/main.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
