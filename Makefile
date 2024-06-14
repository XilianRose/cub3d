# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/10 14:19:38 by mstegema      #+#    #+#                  #
#    Updated: 2024/06/14 16:12:22 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

# compilation
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= -I $(INCDIR)
LIBFT	= libft/bin/libft.a
MLX42	= MLX42/build/libmlx42.a

ifdef AT_HOME
LINKS	= -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
else
LINKS	= -lglfw3 -framework Cocoa -framework OpenGL -framework IOkit
endif

ifdef DEBUG
LINKS	+= -fsanitize=address -g
endif

# directories
SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj
BINDIR	= bin

# sources
SRCS	= src/main.c

# objects
OBJS	= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# colours
PURPLE	= \033[0;35m
NC		= \033[0m

# rules
all: $(LIBFT) $(MLX42) $(BINDIR)/$(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MLX42):
	@cmake -B MLX42/build ./MLX42
	@cmake --build MLX42/build -j4

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(NAME) $(OBJS) $(LIBFT) $(MLX42) $(LINKS)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

debughome:
	$(MAKE) AT_HOME=1 DEBUG=1

debug:
	$(MAKE) DEBUG=1

home:
	$(MAKE) AT_HOME=1

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

.PHONY: all clean fclean re home debug debughome
