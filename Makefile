# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urb-ilya@yandex.ru>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 18:47:10 by nalysann          #+#    #+#              #
#    Updated: 2020/08/24 18:47:12 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

SRC_DIR = src

SRC_CHECKER = checker.c \
              operations.c \
              stack.c

SRC_PUSH_SWAP = push_swap.c

INC_DIR = inc \
          $(LIB_DIR)/inc

OBJ_DIR = obj

OBJ_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.o))

OBJ_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.o))

DEP_CHECKER = $(addprefix $(OBJ_DIR)/, $(SRC_CHECKER:.c=.d))

DEP_PUSH_SWAP = $(addprefix $(OBJ_DIR)/, $(SRC_PUSH_SWAP:.c=.d))

LIB_DIR = libft

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror \
         $(addprefix -I, $(INC_DIR)) \
         -MMD \
         -march=native -O2 -pipe

LDFLAGS = -L $(LIB_DIR) -lft

WHITE = "\033[0;0m"
RED = "\033[1;31m"
BLUE = "\033[1;34m"

.PHONY: all clean fclean re

all:
	@$(MAKE) $(LIB_DIR)/$(LIB)
	@$(MAKE) $(CHECKER)
	@$(MAKE) $(PUSH_SWAP)

$(LIB_DIR)/$(LIB):
	$(MAKE) -sc $(LIB_DIR)

$(CHECKER): $(OBJ_CHECKER) $(LIB_DIR)/$(LIB)
	@$(CC) $(LDFLAGS) $(OBJ_CHECKER) -o $@

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(LIB_DIR)/$(LIB)
	@$(CC) $(LDFLAGS) $(OBJ_PUSH_SWAP) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

include $(wildcard $(DEP_CHECKER))
include $(wildcard $(DEP_PUSH_SWAP))

clean:
	@$(MAKE) clean -sC $(LIB_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -sC $(LIB_DIR)
	@rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all
