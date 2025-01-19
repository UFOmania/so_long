CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT = _libft/libft.a
GNL = _gnl/gnl.a

SRC_PATH = src

SRC = 	src/so_long.c\
		src/map.c
		
OBJ = $(SRC:.c=.o)

NAME= so_long

all: libft gnl $(NAME)

libft:
	make -C _libft/

gnl:
	make -C _gnl/

$(NAME): $(OBJ)
	$(CC) $(GNL) $(LIBFT) $(OBJ) -o $(NAME)

$(SRC_PATH)/%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	make clean -C _libft
	make clean -C _gnl
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(GNL) $(LIBFT)