# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:38:54 by ramedjra          #+#    #+#              #
#    Updated: 2023/03/01 11:03:56 by ramedjra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMMONSRCS = ./src/list_utils.c ./src/instructions.c ./src/utils.c ./src/push_swap_utils.c ./src/input_utils.c
PUSHSWAPSRCS = ./src/push_swap.c
BONUSSRCS = ./src/checker.c

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

NAME = push_swap
BONUS_NAME = checker
FLAGS = -Wall -Werror -Wextra

INPUT:=$(shell seq -5 4 | sort -R)
INPUT1:=$(shell seq 0 2 | sort -R)
INPUT2:=$(shell seq -4 0 | sort -R)
INPUT3:=$(shell seq -50 49 | sort -R)
INPUT4:=$(shell seq -250 249 | sort -R)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT)
	cc $(FLAGS) -o $(NAME) ./src/main.c $(PUSHSWAPSRCS) $(COMMONSRCS) $(LIBFT)

$(BONUS_NAME): $(LIBFT)
	cc $(FLAGS) -o checker ./src/checker_main.c $(BONUSSRCS) $(COMMONSRCS) $(LIBFT)


$(LIBFT):
	make -C $(LIBFT_DIR)
check: $(NAME) $(BONUS_NAME)
	@printf "========= Tests running ... ======== \n \n"
	@printf " running with 3 numbers... \t"
	@./$(NAME) $(INPUT1) | ./checker $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	@./$(NAME) $(INPUT2) | ./checker $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 100 numbers... \t"
	@./$(NAME) $(INPUT3) | ./checker $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 500 numbers... \t"
	@./$(NAME) $(INPUT4) | ./checker $(INPUT4)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT4) | wc -l | tr -d "[:blank:]"

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all bonus

.PHONY: all clean fclean re
