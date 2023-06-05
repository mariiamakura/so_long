COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0;0m

NAME		:= so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX			:= lib/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
MLX42	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT_DIR 			:= lib/libft
LIBFT	:= $(LIBFT_DIR)/libft.a

SRC_DIR := src
OBJ_DIR := build/objects
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

CC := cc

.PHONY: all clean fclean re libmlx libft libmlx_clean libft_clean run

all: $(NAME)

$(NAME): libmlx libft $(OBJ_FILES)
	@echo "Building $(NAME) application"
	@$(CC) $(CFLAGS) $(HEADERS) -o $(NAME) $(OBJ_FILES) $(LIBFT) $(MLX42)
	@echo "$(COLOUR_GREEN)BUILD SUCCESSFUL$(COLOUR_END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./include/so_long.h | $(OBJ_DIR)
	@echo "$(COLOUR_GREEN)Building C object $(notdir $@)$(COLOUR_END)"
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libmlx:
	@echo "Building libmlx library"
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "Building libft library"
	@cd $(LIBFT_DIR) && make all

libmlx_clean:
	@echo "Cleaning MLX42 objects"
	@rm -fr $(LIBMLX)/build

libft_clean:
	@echo "Cleaning libft objects"
	@cd $(LIBFT_DIR) && make clean

clean: libmlx_clean libft_clean
	@echo "Cleaning C objects"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning $(NAME) application"
	@rm -f $(NAME)

run: all
	@./$(NAME) $(ARGS)

re: fclean all
