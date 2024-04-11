# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 18:10:28 by tbraud            #+#    #+#              #
#    Updated: 2024/04/09 06:56:32 by tbraud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap

SRC_DIR	:= src
OBJ_DIR	:= obj

CC		:= clang
CFLAGS	:= -Wextra -Wall -Werror

INCLUDE	:= -I ./include

SRC		:= ft_atoi.c ft_error.c ft_parse.c ft_rules.c ft_rules_two.c \
			ft_sort.c ft_split.c ft_utils.c main.c ft_radix.c
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN	:= \033[1;32m
NC		:= \033[0m

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
