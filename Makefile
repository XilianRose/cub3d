# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/10 14:19:38 by mstegema      #+#    #+#                  #
#    Updated: 2024/07/26 11:29:16 by robertrinh    ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

# compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3
HEADER	= -I $(INCDIR)
LIBFT	= libft/bin/libft.a
MLX42	= MLX42/build/libmlx42.a

ifdef AT_HOME
LINKS	= -Iinclude -lglfw
else
LINKS	= -Iinclude -ldl -lglfw -pthread -lm
endif

ifdef DEBUG
CFLAGS	+= -fsanitize=address -g
endif

# directories
SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj
BINDIR	= bin
BONUSDIR  = src/bonus

# sources
ifdef BONUS
SRCS	= $(BONUSDIR)/main_bonus.c \
	$(BONUSDIR)/map_validation_bonus.c \
	$(BONUSDIR)/map_validation_utils_bonus.c \
	$(BONUSDIR)/get_assets_bonus.c \
	$(BONUSDIR)/window_management_bonus.c \
	$(BONUSDIR)/window_management_utils_bonus.c \
	$(BONUSDIR)/rendering_bonus.c \
	$(BONUSDIR)/rendering_utils_bonus.c \
	$(BONUSDIR)/raycast_bonus.c \
	$(BONUSDIR)/player_movement_bonus.c \
	$(BONUSDIR)/player_rotation_bonus.c \
	$(BONUSDIR)/init_bonus.c \
	$(BONUSDIR)/memory_bonus.c \
	$(BONUSDIR)/utils_bonus.c
else
SRCS	= $(SRCDIR)/main.c \
	$(SRCDIR)/map_validation.c \
	$(SRCDIR)/map_validation_utils.c \
	$(SRCDIR)/get_assets.c \
	$(SRCDIR)/window_management.c \
	$(SRCDIR)/rendering.c \
	$(SRCDIR)/rendering_utils.c \
	$(SRCDIR)/raycast.c \
	$(SRCDIR)/player_movement.c \
	$(SRCDIR)/player_rotation.c \
	$(SRCDIR)/init.c \
	$(SRCDIR)/memory.c \
	$(SRCDIR)/utils.c
endif

# objects
OBJS    = $(SRCS:%.c=$(OBJDIR)/%.o)

# colours
PURPLE	= \033[0;35m
NC		= \033[0m

# rules
all: $(LIBFT) $(MLX42) $(BINDIR)/$(NAME)

$(LIBFT):
	@echo "$(PURPLE)Building libft...$(NC)"
	@$(MAKE) -C ./libft || { echo "Building libft failed"; exit 1; }

$(MLX42):
	@echo "$(PURPLE)Building MLX42...$(NC)"
	@cmake -B MLX42/build ./MLX42 || { echo "CMake configuration for MLX42 failed"; exit 1; }
	@cmake --build MLX42/build -j4 || { echo "Building MLX42 failed"; exit 1; }

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(NAME) $(OBJS) $(CFLAGS) $(LIBFT) $(MLX42) $(LINKS)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

debugathome: fclean
	$(MAKE) AT_HOME=1 DEBUG=1

debug: fclean
	$(MAKE) DEBUG=1

home:
	$(MAKE) AT_HOME=1

bonus: fclean
	$(MAKE) BONUS=1

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJDIR)
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf MLX42/build
	@rm -rf $(BINDIR)
	@echo "$(PURPLE)$(NAME) & directories$(NC) have been removed"

re: fclean all

.PHONY: all clean fclean re home debug debugathome bonus
