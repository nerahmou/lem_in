# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: befuhro <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/30 13:54:18 by befuhro      #+#   ##    ##    #+#        #
#    Updated: 2018/06/29 22:47:32 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_ICYAN=$'\x1b[46m
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m


LEM_PATH = src/

SRC_LEM =	main.c\
			checkers.c\
			checkers2.c\
			getters.c\
			prints.c\
			clears.c\
			get_chemins.c\
			get_chemins2.c\
			get_nb_co.c\
			set_salle2.c\
			getters_salles.c\
			adds.c\
			travel.c\
			send_ants.c\
			send_ants2.c\
			ft_error.c

SRC_LEM_IN = $(addprefix $(LEM_PATH),$(SRC_LEM))
OBJ_LEM_PATH = obj/
OBJ_LEM = $(SRC_LEM:.c=.o)
OBJ = $(addprefix $(OBJ_LEM_PATH),$(OBJ_LEM))
LIBFT_PATH = libft/
INCLUDES = .
LIBFT_INCLUDES = $(addprefix $(LIBFT_PATH),$(INCLUDES))
CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = lem-in


all: $(NAME) 

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@echo "COMPILATION DE $(NAME)"
	@$(CC) $(CFLAGS) -I $(LIBFT_INCLUDES) $^ -o $@ -L libft/ -lft

$(OBJ_LEM_PATH)%.o: $(LEM_PATH)%.c
	@mkdir $(OBJ_LEM_PATH) 2> /dev/null || true
	@echo "COMPILATION DE ($(_BOLD)$(_IRED)$(notdir $<)$(_END)) EN ($(_BOLD)$(_IGREEN)$(notdir $@)$(_END))"
	@$(CC) $(CFLAGS) -I $(LIBFT_INCLUDES) -o $@ -c $<
	@clear

clean:
	@echo "SUPPRESSION FICHIER LEM-IN .O"
	@rm -rf $(OBJ_LEM_PATH) lem-in.dSYM moves
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "SUPPRESSION LEM-IN"
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C lem_in_viz fclean

re: fclean all
