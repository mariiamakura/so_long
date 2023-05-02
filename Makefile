NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

PRINTF = ./printf/libftprintf.a
HEADERS	:= -I ./include -I $(LIBMLX)/include
MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(OBJS) $(PRINTF) $(MLX42) $(HEADERS) -o $(NAME)

$(PRINTF):
	@cd printf && make all

clean:
	@rm -f $(OBJS)
	@rm -fr $(LIBMLX)/build
	@cd printf && make clean

fclean: clean
	@rm -f $(NAME)
	@cd printf && make fclean

run: all
	./$(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx