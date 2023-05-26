COLOUR_GREEN=\033[0;32m

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

LIBFT = ./libft/libft.a
HEADERS	:= -I ./include -I $(LIBMLX)/include
MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS_SO_LONG	:= $(shell find ./src -iname "*.c")
OBJS_SO_LONG	:= ${SRCS_SO_LONG:.c=.o}
SRCS_LINE	:= $(shell find ./get-next-line -iname "*.c")
OBJS_LINE	:= ${SRCS_LINE:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(LIBFT) $(OBJS_SO_LONG) $(OBJS_LINE)
	@$(CC) $(OBJS_SO_LONG) $(OBJS_LINE) $(LIBFT) $(MLX42) $(HEADERS) -o $(NAME)
	@echo "$(COLOUR_GREEN)so_long is done$(COLOUR_END)"

$(LIBFT):
	@cd libft && make all

clean:
	@rm -f $(OBJS_SO_LONG) $(OBJS_LINE)
	@rm -fr $(LIBMLX)/build
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean

run: all
	./$(NAME) maps/map1.ber

re: clean all

.PHONY: all, clean, fclean, re, libmlx