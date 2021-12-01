LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRC_DIR = sources

SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c

SURPL_O = ft_printf.o ft_printf_utils.o

OBJS = ${SRC:.c=.o}

INCLUDES = -I./includes

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES)  $(SRC)
	ar -rc $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
	$(RM) $(SURPL_O)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re : fclean all
