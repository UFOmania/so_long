CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
RM = rm -f

LIBFT = _libft/libft.a
GNL = _gnl/gnl.a

SRC_PATH = src
SRC_PATH = bonus/src

SRC = 	src/so_long.c\
		src/map.c\
		src/map_utils.c\
		src/update.c\
		src/sprite.c\
		src/move.c\
		src/clear.c\

SRCB = 	bonus/src/so_long_bonus.c\
		bonus/src/map.c\
		bonus/src/map_utils.c\
		bonus/src/update.c\
		bonus/src/sprite.c\
		bonus/src/sprite_utils.c\
		bonus/src/move.c\
		bonus/src/clear.c\
		bonus/src/enemy.c\
		
OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

NAME= so_long
NAMEB = so_long_bonus

all: libft gnl $(NAME)

bonus: libft gnl $(NAMEB)

libft:
	make -C _libft/

gnl:
	make -C _gnl/

$(NAME): $(OBJ)
	$(CC) $(GNL) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAMEB):  $(OBJB)
	$(CC) $(GNL) $(LIBFT) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB) 

$(SRC_PATH)/%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) -c $<

$(SRCB_PATH)/%.o: %.c bonus/includes/so_long_bonus.h
	$(CC) $(CFLAGS) -c $<
	
clean:
	make clean -C _libft
	make clean -C _gnl
	$(RM) $(OBJ) $(OBJB)

re: fclean all

fclean: clean
	$(RM) $(NAME) $(GNL) $(LIBFT)