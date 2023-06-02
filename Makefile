COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0;0m

NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX			:= lib/MLX42
LIBMLX_INCLUDE	:= -I ./include -I $(LIBMLX)/include
LIBMLX_CFLAGS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT 			:= lib/libft
LIBFT_CFLAGS	:= $(LIBFT)/libft.a

INPUT	:= $(shell find ./src -iname "*.c")
OUTPUT	:= ${INPUT:.c=.o}

libmlx:
	@echo "Building libmlx library"
	@cd $(LIBMLX) && cmake -B build && make -C build -j4

libmlx_clean:
	@echo "Cleaning libmlx library"
	@cd $(LIBMLX) && cmake --build build --target clean

libft:
	@echo "Building libft library"
	@cd $(LIBFT) && make all

libft_clean:
	@echo "Cleaning libft library"
	@cd $(LIBFT) && make fclean

%.o: %.c
	@echo "$(COLOUR_GREEN)Building C object $(notdir $<).o$(COLOUR_END)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIBMLX_INCLUDE)

$(NAME): libmlx libft $(OUTPUT)
	@echo "Building $(NAME) application"
	@$(CC) $(OUTPUT) $(LIBFT_CFLAGS) $(LIBMLX_CFLAGS) $(LIBMLX_INCLUDE) -o $(NAME)

all: $(NAME)
	@echo "$(COLOUR_GREEN)BUILD SUCCESSFUL$(COLOUR_END)"

clean: libmlx_clean libft_clean
	@echo "Cleaning C objects"
	@rm -f $(OUTPUT)

fclean: clean
	@echo "Cleaning $(NAME) application"
	@rm -f $(NAME)

run: all
	./$(NAME) $(ARGS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx