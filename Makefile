NAME		= test_mlx
GCC			= clang
CFLAGS		= -Wall -Wextra -Werror
ifeq ($(main), 2)
	SRCS	= ./srcs/test_mlx2.c
else
	SRCS	= ./srcs/test_mlx.c
endif
OBJS		=   $(SRCS:.c=.o)

INCLUDES	= ./includes/
LIBFT_DIR	= ./libft/
MLX_DIR		= ./minilibx-linux/
LIBFT		= libft.a
MLX			= compmlx

ALL_INC		= -I$(INCLUDES) -I$(LIBFT_DIR)/includes/ -I$(MLX_DIR)
ALL_LIB		= -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -L$(LIBFT_DIR) -lft


all: $(NAME)

$(OBJS): %.o: %.c
	$(GCC) $(CFLAGS) -c $< -o $@ $(ALL_INC)

$(NAME): $(MLX) $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@ $(ALL_INC) $(ALL_LIB)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	$(MAKE) -C $(MLX_DIR)

clean:
# 	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) -R $(MLX_DIR)*.o
	$(RM) -R ./srcs/*.o

fclean: clean
# 	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean
	$(MAKE)