CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o)



all: $(NAME)

%.o : %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all