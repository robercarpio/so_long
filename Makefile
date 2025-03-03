SRCS = main.c \
       aux/allocate_map.c \
       aux/borders_h_checker.c \
       aux/borders_v_checker.c \
       aux/consume_remaining.c \
       aux/dup_line.c \
       aux/files_map.c \
       aux/fill_cross.c \
       aux/fill_down.c \
       aux/fill_left.c \
       aux/fill_right.c \
       aux/fill_up.c \
       aux/pos_x.c \
       aux/pos_y.c \
       aux/ft_contains.c \
       aux/line_len.c \
       aux/map_height.c \
       aux/only_chars_allowed.c \
       aux/collectibles_count.c \
       aux/ber_file.c \
       aux/str_compare.c \
       aux/str_join.c \
       aux/count_char.c \
       aux/print_error.c \
       aux/coord_x.c \
       aux/coord_y.c \
       aux/put_int.c \
       gnl/get_next_line.c \
       gnl/aux.c \
       gnl/get_next_line_utils.c \
       print_map/init.c \
       print_map/print_map.c \
       print_map/play.c \
       events/events.c \
       events/movement.c \
       process_map/is_playable.c \
       process_map/map_checkers.c

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
INCLUDES = so_long.h

all: $(NAME)
	@echo "OK"
$(NAME): $(OBJS)
	cd $(MLX_DIR) && $(MAKE) > /dev/null 2>/dev/null
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "compilation completed"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	@cd $(MLX_DIR) && $(MAKE)
	@rm -f $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fully clean"

re: fclean all

.PHONY: clean fclean all re
