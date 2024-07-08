LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

SRC = fractol.c init.c render.c hooks.c sets.c help_msg.c color.c
OBJ = $(SRC:.c=.o)
NAME = fractol
# -L flag indicates which directories need to be searched for libraries (.a files)
# -I flad adds a directory that needs to be searched for Header files (.h files)
FLAGS = -Wall -Wextra -Werror -g -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -L$(LIBFT_DIR) -lft
CC = cc
HEADER = fractol.h

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS)

# Compile each c file into o file (-o specifies name of output file, -c tells compiler to compile src file into obj but not to link it)
%.o: %.c $(HEADER)
	$(CC) -g -Wall -Wextra -Werror -I/usr/include -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clone:
	git clone https://github.com/42Paris/minilibx-linux.git

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re clone
