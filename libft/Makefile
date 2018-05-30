# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 15:09:05 by edbernie     #+#   ##    ##    #+#        #
#    Updated: 2018/05/30 14:53:13 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./includes/
FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c get_next_line.c ft_strndup.c ft_putwchar.c ft_putwstr.c ft_putnwstr.c ft_itoa_base.c ft_uitoa.c ft_putwlen.c ft_strwlen.c ft_strnwlen.c ft_printf.c ft_conversion.c ft_int.c ft_flagh.c ft_affichage.c ft_aff_suite.c ft_affichage_to_x.c ft_o.c ft_x.c ft_u.c ft_c.c ft_pourcent.c ft_affichage_string.c ft_affichage_unicode.c ft_justtaille.c ft_string.c ft_flag.c ft_tablength.c ft_strchr_occur.c ft_char_pos.c
SRC = $(addprefix $(PATH_SRC), $(FILES))
OBJ = $(addprefix $(PATH_OBJ), $(FILES:.c=.o))
INC = $(addprefix $(PATH_INC), libft.h)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "COMPILATION DE LA $(NAME)"
	@ar rcs $(NAME) $(OBJ)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@echo "COMPILATION DE $< EN $@"
	@$(CC) $(CC_FLAGS) -I $(PATH_INC) -o $@ -c $<

clean:
	@echo "SUPPRESSION FICHIER .O"
	@rm -rf $(OBJ)

fclean: clean
	@echo "SUPPRESSION LIBFT.A"
	@rm -rf $(NAME)

re: fclean all
