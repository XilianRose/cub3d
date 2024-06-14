# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/16 12:00:14 by mstegema      #+#    #+#                  #
#    Updated: 2023/07/12 14:39:50 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# target
NAME = libft.a

# directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
BINDIR = bin

# sources
SRCS = src/ft_isalpha.c \
	src/ft_isdigit.c \
	src/ft_isalnum.c \
	src/ft_isascii.c \
	src/ft_isprint.c \
	src/ft_strlen.c \
	src/ft_memset.c \
	src/ft_bzero.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_strlcpy.c \
	src/ft_strlcat.c \
	src/ft_toupper.c \
	src/ft_tolower.c \
	src/ft_strchr.c \
	src/ft_strrchr.c \
	src/ft_strncmp.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_strnstr.c \
	src/ft_atoi.c \
	src/ft_calloc.c \
	src/ft_strdup.c \
	src/ft_substr.c \
	src/ft_strjoin.c \
	src/ft_strtrim.c \
	src/ft_split.c \
	src/ft_itoa.c \
	src/ft_strmapi.c \
	src/ft_striteri.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_lstnew.c \
	src/ft_lstadd_front.c \
	src/ft_lstsize.c \
	src/ft_lstlast.c \
	src/ft_lstadd_back.c \
	src/ft_lstdelone.c \
	src/ft_lstclear.c \
	src/ft_lstiter.c \
	src/ft_lstmap.c \
	src/ft_printf.c \
	src/ft_printf_csnx.c \
	src/get_next_line_bonus.c \
	src/get_next_line_utils_bonus.c \
	src/my_intlen.c \
	src/my_strendstr.c \
	src/my_freestr.c \
	src/my_realloc.c \
	src/my_allocarray.c \
	src/my_freearray.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS = -Wall -Wextra -Werror
HEADER = $(INCDIR)/libft.h
PURPLE = \033[0;35m
NC = \033[0m

# rules
all: $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	@ar -rcs $(BINDIR)/$(NAME) $(OBJS)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@cc -c $(CFLAGS) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@rm -rf $(BINDIR)
	@echo "$(PURPLE)$(NAME) & directories$(NC) have been removed"

re: fclean all

.PHONY: all clean fclean re
