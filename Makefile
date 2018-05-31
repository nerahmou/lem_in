# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/30 13:54:18 by befuhro      #+#   ##    ##    #+#        #
#    Updated: 2018/05/31 12:15:26 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

LEM_PATH = src/

SRC_LEM =	main.c\
			checkers.c\
			getters.c\
			prints.c\
			clears.c\
			adds.c

SRC_LEM_IN = $(addprefix $(LEM_PATH),$(SRC_LEM))
OBJ_LEM_PATH = obj/
OBJ_LEM = $(SRC_LEM:.c=.o)
OBJ = $(addprefix $(OBJ_LEM_PATH),$(OBJ_LEM))
LIBFT_PATH = libft/
INCLUDES = .
LIBFT_INCLUDES = $(addprefix $(LIBFT_PATH),$(INCLUDES))
CC = clang -g
CFLAGS = -Wall -Wextra -Werror
NAME = lem-in

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@echo "COMPILATION DE $(NAME)"
	@$(CC) $(CFLAGS) -I $(LIBFT_INCLUDES) $^ -o $@ -L libft/ -lft

$(OBJ_LEM_PATH)%.o: $(LEM_PATH)%.c
	@mkdir $(OBJ_LEM_PATH) 2> /dev/null || true
	@echo "COMPILATION DE $< EN $@"
	@$(CC) $(CFLAGS) -I $(LIBFT_INCLUDES) -o $@ -c $<

clean:
	@echo "SUPPRESSION FICHIER LEM-IN .O"
	@rm -rf $(OBJ_LEM_PATH) lem-in.dSYM
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "SUPPRESSION LEM-IN"
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all
