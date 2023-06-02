COLOUR_GREEN=\033[0;32m

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

LIBFT = ./lib/libft/libft.a
HEADERS	:= -I ./include -I $(LIBMLX)/include
MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS_SO_LONG	:= $(shell find ./src -iname "*.c")
OBJS_SO_LONG	:= ${SRCS_SO_LONG:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(LIBFT) $(OBJS_SO_LONG)
	@$(CC) $(OBJS_SO_LONG) $(LIBFT) $(MLX42) $(HEADERS) -o $(NAME)
	@echo "$(COLOUR_GREEN)so_long is done$(COLOUR_END)"

$(LIBFT):
	@cd lib/libft && make all

clean:
	@rm -f $(OBJS_SO_LONG)
	@rm -fr $(LIBMLX)/build
	@cd lib/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd lib/libft && make fclean

run: all
	./$(NAME) $(ARGS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx