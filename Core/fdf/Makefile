NAME		:= fdf
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
CFLAGS		:=
CC 			:= gcc

LIBMLX_PATH	:= ./lib/mlx
LIBMLX_NAME	:= /build/libmlx42.a
LIBMLX		:= $(LIBMLX_PATH)$(LIBMLX_NAME) -ldl -lglfw -pthread -lm

LIBFT_PATH	:= ./lib/libft/
LIBFT_NAME	:= libft.a
LIBFT		:= $(LIBFT_PATH)$(LIBFT_NAME)

INC_LIBMLX	:= -I ./include -I $(LIBMLX_PATH)/include
INC_LIBFT	:= -I ./libft

SRC_PATH	:= src/
SRC			:= fdf.c read_file.c draw.c
SRCS		:= $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH:= obj/
OBJ	:= ${SRC:.c=.o}
OBJS	:= $(addprefix $(OBJ_PATH), $(OBJ))

BOLD =	\033[1m
GREEN =	\033[32m
RED =	\033[31m
BCYAN =	\033[96m
NC =	\033[0m

all: libft libmlx $(NAME)

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_LIBMLX) $(INC_LIBFT)

$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

libft:
	@echo "$(BOLD)$(BCYAN)[ Making libft... ]$(NC)"
	@make -sC $(LIBFT_PATH)
	@echo "$(BOLD)$(GREEN)[ Libft ready! ]$(NC)"

libmlx:
	@echo "$(BOLD)$(BCYAN)[ Making MLX42... ]$(NC)"
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4
	@echo "$(BOLD)$(GREEN)[ MLX42 ready! ]$(NC)"

$(NAME): $(OBJS)
	@echo "$(BOLD)$(BCYAN)[ Compiling $(NAME)... ]$(NC)"
	@$(CC) $(OBJS) $(LIBMLX) $(INC_LIBMLX) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[ $(NAME) ready! ]$(NC)"

clean:
	@rm -Rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -Rf $(LIBMLX_PATH)/build
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(BOLD)$(RED)[ Obj files deleted ]$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(BOLD)$(RED)[ Program deleted ]$(NC)"

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
