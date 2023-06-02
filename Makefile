COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0;0m

NAME_DIR	:= build/target
NAME		:= $(NAME_DIR)/so_long
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX			:= lib/MLX42
LIBMLX_INCLUDE	:= -I ./include -I $(LIBMLX)/include
LIBMLX_CFLAGS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

LIBFT 			:= lib/libft
LIBFT_CFLAGS	:= $(LIBFT)/libft.a

SRC_DIR := src
OBJ_DIR := build/objects
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

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

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME_DIR):
	@mkdir $(NAME_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@echo "$(COLOUR_GREEN)Building C object $(notdir $<).o$(COLOUR_END)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(LIBMLX_INCLUDE)

$(NAME): libmlx libft $(OBJ_FILES) $(NAME_DIR)
	@echo "Building $(NAME) application"
	@$(CC) $(OBJ_FILES) $(LIBFT_CFLAGS) $(LIBMLX_CFLAGS) $(LIBMLX_INCLUDE) -o $(NAME)

all: $(NAME)
	@echo "$(COLOUR_GREEN)BUILD SUCCESSFUL$(COLOUR_END)"

clean: libmlx_clean libft_clean
	@echo "Cleaning C objects"
	@rm -f $(OBJ_FILES)

fclean: clean
	@echo "Cleaning $(NAME) application"
	@rm -f $(NAME)

run: all
	./$(NAME) $(ARGS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx